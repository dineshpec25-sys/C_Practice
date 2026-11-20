# Week 1: Environment Mastery - Daily Plan
**Goal:** Reproducible cross-compilation, kernel build, QEMU, git workflow  
**Target:** Boot custom kernel on QEMU with custom initramfs by Saturday  

---

## Daily Schedule (5 hrs/day)

```
06:30-07:00  Review yesterday / Plan today
07:00-08:00  Theory (1 hr)
08:00-08:15  Break
08:15-11:15  Hands-on Coding (3 hrs)
11:15-11:30  Break
11:30-12:00  Git commit / Review / Notes (30 min)
```

---

## Day 1 (Monday): Cross-Compilation Toolchain

### Theory (1 hr)
- Read: Toolchain components (binutils, gcc, glibc, linux-headers)
- Understand: `--target`, `--prefix`, `--sysroot`, multilib
- Difference: `arm-linux-gnueabihf` vs `aarch64-linux-gnu`

### Hands-on (3 hrs)
```bash
# 1. Install toolchains
sudo apt update && sudo apt install -y \
  gcc-arm-linux-gnueabihf gcc-aarch64-linux-gnu \
  qemu-system-arm qemu-system-aarch64 \
  libncurses-dev libssl-dev bc flex bison libelf-dev

# 2. Verify
arm-linux-gnueabihf-gcc --version
aarch64-linux-gnu-gcc --version

# 3. Test cross-compile
cat > hello.c << 'EOF'
#include <stdio.h>
int main() { printf("Hello from %s\n", __ARCH__); return 0; }
EOF
arm-linux-gnueabihf-gcc -static hello.c -o hello-arm
aarch64-linux-gnu-gcc -static hello.c -o hello-arm64

# 4. Run in QEMU user-mode
qemu-arm ./hello-arm
qemu-aarch64 ./hello-arm64

# 5. Create setup script
cat > ~/setup-toolchain.sh << 'EOF'
#!/bin/bash
# Toolchain verification script
echo "=== Toolchain Versions ==="
arm-linux-gnueabihf-gcc --version | head -1
aarch64-linux-gnu-gcc --version | head -1
echo "=== QEMU Versions ==="
qemu-system-arm --version | head -1
qemu-system-aarch64 --version | head -1
EOF
chmod +x ~/setup-toolchain.sh
```

### Git/Review (30 min)
```bash
cd ~/C_Practice
git add kernel-journey/week-01-environment.md
git commit -m "week1: Day 1 - Cross-compilation toolchain setup"
git log --oneline -3
```

---

## Day 2 (Tuesday): Kernel Build System (Kbuild)

### Theory (1 hr)
- Read: `Documentation/kbuild/` (kconfig.txt, makefiles.txt, modules.txt)
- Understand: Kconfig symbols, `make defconfig`, `make menuconfig`, `make -j$(nproc)`

### Hands-on (3 hrs)
```bash
# 1. Clone kernel
cd ~/C_Practice
git clone --depth=1 --branch v6.6 https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
cd linux

# 2. Default configs
make ARCH=arm64 defconfig
make ARCH=arm64 -j$(nproc) 2>&1 | tee build-arm64.log
# Check: Image size, build time, warnings

make ARCH=arm qemu_arm_defconfig
make ARCH=arm -j$(nproc) 2>&1 | tee build-arm.log

# 3. Analyze .config
cat > ~/analyze-config.sh << 'EOF'
#!/bin/bash
echo "=== Config Comparison ==="
echo "ARM64: $(grep -c '^CONFIG_' .config-arm64) options"
echo "ARM:   $(grep -c '^CONFIG_' .config-arm) options"
echo "=== Key Differences ==="
diff -u <(grep '^CONFIG_' .config-arm64 | sort) <(grep '^CONFIG_' .config-arm | sort) | head -50
EOF
# Run after both builds: cp .config .config-arm64 && make ARCH=arm qemu_arm_defconfig && cp .config .config-arm

# 4. Build kernel modules
make ARCH=arm64 modules_prepare
```

### Git/Review (30 min)
```bash
cd ~/C_Practice/linux
git add .
git commit -m "week1: Day 2 - Kernel build for ARM64 and ARM"
cd ~/C_Practice
git add kernel-journey/
git commit -m "week1: Day 2 - Build analysis scripts"
```

---

## Day 3 (Wednesday): Kernel Configuration Deep Dive

### Theory (1 hr)
- `make menuconfig` navigation
- Key config categories: General, Block, Network, Device Drivers, FS, Kernel Hacking
- Config fragments: `merge_config.sh`

### Hands-on (3 hrs)
```bash
cd ~/C_Practice/linux

# 1. Save base configs
make ARCH=arm64 defconfig
cp .config ../kernel-configs/arm64-defconfig
make ARCH=arm qemu_arm_defconfig
cp .config ../kernel-configs/arm-qemu-defconfig

# 2. Custom minimal config for QEMU
cat > ../kernel-configs/qemu-arm64-minimal.config << 'EOF'
CONFIG_64BIT=y
CONFIG_ARM64=y
CONFIG_SMP=y
CONFIG_NR_CPUS=4
CONFIG_KERNEL_MODE_NEON=y
CONFIG_SERIAL_AMBA_PL011=y
CONFIG_SERIAL_AMBA_PL011_CONSOLE=y
CONFIG_VIRTIO=y
CONFIG_VIRTIO_MMIO=y
CONFIG_VIRTIO_NET=y
CONFIG_VIRTIO_BLK=y
CONFIG_VIRTIO_CONSOLE=y
CONFIG_9P_FS=y
CONFIG_9P_FS_POSIX_ACL=y
CONFIG_9P_FS_SECURITY=y
CONFIG_DEVTMPFS=y
CONFIG_DEVTMPFS_MOUNT=y
CONFIG_TMPFS=y
CONFIG_INITRAMFS_SOURCE=""
CONFIG_CMDLINE="console=ttyAMA0 root=/dev/vda rw"
EOF

# 3. Build with custom config
make ARCH=arm64 O=build/qemu-arm64 ../kernel-configs/qemu-arm64-minimal.config
make ARCH=arm64 O=build/qemu-arm64 -j$(nproc)

# 4. Compare sizes
ls -lh arch/arm64/boot/Image
ls -lh build/qemu-arm64/arch/arm64/boot/Image
```

### Git/Review (30 min)
```bash
cd ~/C_Practice
git add kernel-configs/
git commit -m "week1: Day 3 - Custom kernel configs for QEMU"
```

---

## Day 4 (Thursday): QEMU Mastery

### Theory (1 hr)
- Machine types: `virt`, `raspi3`, `virt-2.12`
- CPU models: `cortex-a57`, `cortex-a72`, `max`
- Devices: `-drive`, `-netdev`, `-device virtio-net-pci`, `-fsdev`, `-device virtio-9p-pci`
- Console: `-nographic`, `-serial stdio`

### Hands-on (3 hrs)
```bash
cd ~/C_Practice/linux

# 1. Create initramfs
mkdir -p ~/initramfs/{bin,sbin,etc,proc,sys,dev,root}
cat > ~/initramfs/init << 'EOF'
#!/bin/sh
mount -t proc none /proc
mount -t sysfs none /sys
mount -t devtmpfs none /dev
mount -t 9p -o trans=virtio,version=9p2000.L hostshare /mnt
echo "=== Custom initramfs booted ==="
exec /bin/sh
EOF
chmod +x ~/initramfs/init
cd ~/initramfs && find . | cpio -o -H newc | gzip > ../initramfs.cpio.gz

# 2. Boot ARM64 kernel
qemu-system-aarch64 \
  -machine virt \
  -cpu cortex-a57 \
  -m 512M \
  -smp 2 \
  -kernel build/qemu-arm64/arch/arm64/boot/Image \
  -initrd ../initramfs.cpio.gz \
  -append "console=ttyAMA0 earlycon=pl011,0x09000000" \
  -nographic

# 3. Boot with rootfs (need to create)
# Create disk image
qemu-img create -f raw rootfs.img 2G
# Format and populate later

# 4. Networking test
qemu-system-aarch64 \
  -machine virt -cpu cortex-a57 -m 512M -smp 2 \
  -kernel build/qemu-arm64/arch/arm64/boot/Image \
  -initrd ../initramfs.cpio.gz \
  -append "console=ttyAMA0 earlycon=pl011,0x09000000" \
  -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  -device virtio-net-pci,netdev=net0 \
  -nographic

# 5. Create launch scripts
cat > ~/launch-qemu-arm64.sh << 'EOF'
#!/bin/bash
qemu-system-aarch64 \
  -machine virt -cpu cortex-a57 -m 512M -smp 2 \
  -kernel ~/C_Practice/linux/build/qemu-arm64/arch/arm64/boot/Image \
  -initrd ~/initramfs.cpio.gz \
  -append "console=ttyAMA0 earlycon=pl011,0x09000000" \
  -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  -device virtio-net-pci,netdev=net0 \
  -fsdev local,id=fsdev0,path=/home/dinesh,security_model=none \
  -device virtio-9p-pci,fsdev=fsdev0,mount_tag=hostshare \
  -nographic
EOF
chmod +x ~/launch-qemu-arm64.sh
```

### Git/Review (30 min)
```bash
cd ~/C_Practice
cat > kernel-journey/qemu-launchers/launch-qemu-arm64.sh << 'EOF'
#!/bin/bash
# QEMU ARM64 launch script
qemu-system-aarch64 \
  -machine virt -cpu cortex-a57 -m 512M -smp 2 \
  -kernel ~/C_Practice/linux/build/qemu-arm64/arch/arm64/boot/Image \
  -initrd ~/initramfs.cpio.gz \
  -append "console=ttyAMA0 earlycon=pl011,0x09000000" \
  -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  -device virtio-net-pci,netdev=net0 \
  -fsdev local,id=fsdev0,path=/home/dinesh,security_model=none \
  -device virtio-9p-pci,fsdev=fsdev0,mount_tag=hostshare \
  -nographic
EOF
mkdir -p kernel-journey/qemu-launchers
git add kernel-journey/qemu-launchers/
git commit -m "week1: Day 4 - QEMU launch scripts"
```

---

## Day 5 (Friday): Git Workflow for Kernel Development

### Theory (1 hr)
- Read: `Documentation/process/submitting-patches.rst`
- Commit message format: `subsystem: short description`
- `Signed-off-by:`, `Fixes:`, `Cc:`, `Link:`
- `git format-patch`, `git send-email`, `b4` tool

### Hands-on (3 hrs)
```bash
cd ~/C_Practice/linux

# 1. Configure git for kernel
git config user.name "Your Name"
git config user.email "your@email.com"
git config format.signoff true

# 2. Practice commit
git checkout -b test/commit-msg
echo "test" > test.txt
git add test.txt
git commit -s -m "test: add test file for commit practice"
git log -1 --format=fuller

# 3. Format patch
git format-patch -1 -o ../patches/
cat ../patches/0001-test-add-test-file-for-commit-practice.patch

# 4. Configure send-email (dry-run)
git config sendemail.smtpserver smtp.gmail.com
git config sendemail.smtpencryption tls
git config sendemail.smtpserverport 587
git config sendemail.smtpuser your@gmail.com
# git send-email --to=self --dry-run ../patches/0001-*.patch

# 5. Get maintainer script
./scripts/get_maintainer.pl ../patches/0001-*.patch

# 6. Clean up
git checkout master
git branch -D test/commit-msg
rm test.txt
```

### Git/Review (30 min)
```bash
cd ~/C_Practice
git add kernel-journey/
git commit -m "week1: Day 5 - Git workflow practice and patch formatting"
```

---

## Day 6 (Saturday): Mini-Project - Complete Boot Pipeline

### Goal: Build kernel → Boot QEMU → Run custom initramfs with hello world

### Hands-on (5 hrs)
```bash
cd ~/C_Practice

# 1. Create complete initramfs with hello world
mkdir -p ~/initramfs-full/{bin,sbin,etc,proc,sys,dev,root,mnt}
cat > ~/initramfs-full/init << 'EOF'
#!/bin/sh
mount -t proc none /proc
mount -t sysfs none /sys
mount -t devtmpfs none /dev
mkdir -p /mnt/host
mount -t 9p -o trans=virtio,version=9p2000.L hostshare /mnt/host 2>/dev/null || true

echo "=== Kernel Journey - Week 1 Complete ==="
echo "Kernel: $(uname -r)"
echo "Arch:   $(uname -m)"
echo "Time:   $(date)"
echo ""
echo "Hello from custom initramfs!"
echo "Host files accessible at /mnt/host"
echo ""

# Drop to shell
exec /bin/sh
EOF
chmod +x ~/initramfs-full/init

# 2. Add busybox for shell
# Option A: Use busybox static
sudo apt install -y busybox-static
cp $(which busybox) ~/initramfs-full/bin/
cd ~/initramfs-full/bin
for cmd in sh ls cat echo mount umount ps; do
  ln -s busybox $cmd
done

# 3. Build initramfs
cd ~/initramfs-full
find . | cpio -o -H newc | gzip > ~/initramfs-full.cpio.gz

# 4. Final kernel build (ensure config has 9p, virtio)
cd ~/C_Practice/linux
make ARCH=arm64 O=build/qemu-final \
  ../kernel-configs/qemu-arm64-minimal.config
make ARCH=arm64 O=build/qemu-final -j$(nproc)

# 5. Boot and verify
qemu-system-aarch64 \
  -machine virt -cpu cortex-a57 -m 512M -smp 2 \
  -kernel build/qemu-final/arch/arm64/boot/Image \
  -initrd ~/initramfs-full.cpio.gz \
  -append "console=ttyAMA0 earlycon=pl011,0x09000000" \
  -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  -device virtio-net-pci,netdev=net0 \
  -fsdev local,id=fsdev0,path=/home/dinesh,security_model=none \
  -device virtio-9p-pci,fsdev=fsdev0,mount_tag=hostshare \
  -nographic

# Inside QEMU, you should see:
# === Kernel Journey - Week 1 Complete ===
# Kernel: 6.6.x
# Arch:   aarch64
# Hello from custom initramfs!
# Host files accessible at /mnt/host
# / # _
```

### Deliverable
```bash
cd ~/C_Practice
git add kernel-journey/
git commit -m "week1: Day 6 - Complete boot pipeline: kernel + initramfs + QEMU"
git tag week1-complete
```

---

## Day 7 (Sunday): Rest & Reading

### Reading (1-2 hrs)
- `Documentation/process/submitting-patches.rst` (full)
- `Documentation/admin-guide/` (kernel-parameters.txt, serial-console.txt)
- LWN.net "Kernel page" - recent articles
- Kernel Newbies: "Kernel Hacking" guide

### Light Tasks
```bash
# Organize notes
mkdir -p ~/C_Practice/kernel-journey/notes/week1
cat > ~/C_Practice/kernel-journey/notes/week1/summary.md << 'EOF'
# Week 1 Summary

## What Worked
- Cross-compilation: arm-linux-gnueabihf, aarch64-linux-gnu
- Kernel build: defconfig, custom config, O= out-of-tree
- QEMU: ARM64 virt machine, initramfs, 9pfs host share
- Git: format-patch, get_maintainer, signed commits

## Issues/Fixes
- [ ] 
- [ ]

## Next Week Focus
- Kernel source navigation (cscope/ctags)
- printk/pr_debug/dynamic debug
- kgdb + gdb debugging
- crash utility
- ftrace basics
EOF
```

---

## Week 1 Checklist

| Task | Status |
|------|--------|
| Cross-compile toolchains installed | [ ] |
| Hello world cross-compiled & run in QEMU user-mode | [ ] |
| Kernel cloned, built for ARM64 & ARM | [ ] |
| Custom minimal kernel config created | [ ] |
| Initramfs with busybox created | [ ] |
| QEMU ARM64 boot with custom kernel + initramfs | [ ] |
| 9pfs host share working | [ ] |
| Git config for kernel development | [ ] |
| format-patch + get_maintainer tested | [ ] |
| Week 1 tagged | [ ] |

---

## Files Created This Week

```
~/C_Practice/
├── kernel-journey/
│   ├── week-01-environment.md
│   ├── qemu-launchers/
│   │   └── launch-qemu-arm64.sh
│   ├── kernel-configs/
│   │   ├── arm64-defconfig
│   │   ├── arm-qemu-defconfig
│   │   └── qemu-arm64-minimal.config
│   ├── patches/
│   │   └── 0001-test-*.patch
│   └── notes/week1/
│       └── summary.md
├── linux/ (kernel source)
│   └── build/qemu-final/
├── initramfs-full.cpio.gz
└── setup-toolchain.sh
```