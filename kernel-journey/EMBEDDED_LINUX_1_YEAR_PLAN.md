# Embedded Linux Kernel Engineer - 1 Year Mastery Plan
**Target:** Send patches to mainline Linux kernel  
**Starting Level:** 2nd Year ECE, strong C basics, ATmega bare-metal experience  
**Commitment:** 5 hours/day × 365 days = ~1,825 hours  
**Start Date:** Today  

---

## PHILOSOPHY

> **"The kernel is not a black box. It's C code you can read, understand, and improve."**

**Core Loop (Daily):**
```
1 hr Theory/Reading  →  3 hrs Hands-on Coding  →  1 hr Review/Notes/Git
```

**Success Metrics:**
- Week 12: Run custom kernel on QEMU + hardware
- Week 24: Write and test a real driver subsystem
- Week 36: Understand kernel internals deeply (MM, scheduler, VFS)
- Week 52: Submit 3+ patches to LKML (Linux Kernel Mailing List)

---

## PHASE OVERVIEW

| Phase | Weeks | Focus | Outcome |
|-------|-------|-------|---------|
| **0** | 1-2 | Environment Mastery | Reproducible cross-compile, QEMU, git workflow |
| **1** | 3-8 | Kernel-Style C & Data Structures | `list_head`, `rb_tree`, `kfifo`, lockless rings |
| **2** | 9-16 | Kernel Modules & Char Drivers | 5+ drivers, sysfs/proc, ioctl, async I/O |
| **3** | 17-24 | Platform Drivers & Device Tree | I2C/SPI/USB subsystems, DT bindings, PM |
| **4** | 25-32 | Memory Management & Concurrency | Slab, page alloc, RCU, lockdep, perf |
| **5** | 33-40 | Subsystem Deep Dives | Block, Net, FS, GPU, DMA, Interrupts |
| **6** | 41-48 | Testing, Tracing, Debugging | KUnit, selftests, ftrace, eBPF, KCSAN |
| **7** | 49-52 | Upstream Contribution | 3+ patches to LKML, maintainer interaction |

---

## DETAILED WEEKLY PLANS

---

### PHASE 0: ENVIRONMENT MASTERY (Weeks 1-2)

#### Week 1: Toolchain & Build Systems
**Goal:** Reproducible cross-compilation, kernel build, QEMU, git mastery

| Day | Theory (1h) | Hands-on (3h) | Review (1h) |
|-----|-------------|---------------|-------------|
| Mon | Cross-compile theory: toolchain components, sysroot, multilib | Install `arm-linux-gnueabihf-gcc`, `aarch64-linux-gnu-gcc`, build hello.c for both | Document toolchain versions, create `setup-toolchain.sh` |
| Tue | Kbuild system: Kconfig, Makefile, modules.builtin | Clone kernel.org linux.git, `make defconfig`, `make -j$(nproc)`, analyze build output | Map Kbuild variables, create cheat sheet |
| Wed | Kernel config: menuconfig, defconfig, fragments | Build for `qemu_arm64_defconfig`, `qemu_x86_64_defconfig`, compare .config size | Config comparison script |
| Thu | QEMU deep dive: -machine, -cpu, -kernel, -initrd, -drive, -netdev | Boot kernel in QEMU (ARM64 + x86_64), serial console, virtio-net, 9pfs share | QEMU launch scripts repo |
| Fri | Git workflow: signed commits, format-patch, send-email, b4 | Configure git (user, signingkey, sendemail), `git format-patch -1`, test send to self | Git config dotfiles |
| Sat | **Mini-Project** | **Build kernel → boot QEMU → run custom initramfs with your hello world** | Push to GitHub: `kernel-env-setup` |
| Sun | Rest / Reading | Read: `Documentation/process/submitting-patches.rst`, `Documentation/admin-guide/` | Notes in Obsidian/Notion |

**Deliverable:** `kernel-env-setup/` repo with scripts, configs, QEMU launchers, documented workflow

---

#### Week 2: Kernel Source Navigation & Debugging
**Goal:** Navigate 30M+ lines, use cscope/ctags, basic debugging

| Day | Theory (1h) | Hands-on (3h) | Review (1h) |
|-----|-------------|---------------|-------------|
| Mon | Kernel source layout: init/, kernel/, mm/, fs/, net/, drivers/, include/ | Generate tags: `make tags cscope`, practice jumping in vim/vscode | Tag navigation cheat sheet |
| Tue | `printk`, `pr_debug`, `dev_dbg`, dynamic debug, `trace_printk` | Add debug to kernel, boot, filter via `dmesg -T`, `grep` | Debug macro reference |
| Wed | kgdb + gdb: kgdboc, kgdbwait, earlycon | Attach gdb to QEMU, break at `start_kernel`, step through initcalls | kgdb cheat sheet |
| Thu | Crash utility: vmcore analysis, `crash > bt`, `ps`, `kmem` | Panic kernel intentionally (`BUG()`), analyze with crash | Crash commands reference |
| Fri | ftrace: trace-cmd, kernelshark, function_graph, latency | Trace `schedule()`, `sys_read()`, analyze wakeup latency | ftrace recipe cards |
| Sat | **Mini-Project** | **Instrument kernel: trace all syscalls from userspace app, visualize with kernelshark** | Push: `kernel-tracing-lab/` |
| Sun | Rest / Reading | `Documentation/trace/ftrace.rst`, `Documentation/dev-tools/kgdb.rst` | Notes |

**Deliverable:** `kernel-tracing-lab/` with trace scripts, visualization, analysis notes

---

### PHASE 1: KERNEL-STYLE C & DATA STRUCTURES (Weeks 3-8)

#### Week 3: Kernel Linked Lists & Hash Tables
**Goal:** Master `include/linux/list.h`, `hlist`, `list_lru`, `kfifo`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | `list_head` design: intrusive, circular, RCU-safe | Implement all `list_*_rcu` APIs in userspace test | |
| Tue | `hlist_head` for hash tables, `hash_add_rcu` | Build hash table with 10k entries, benchmark vs glibc | |
| Wed | `list_lru` for shrinker integration | Simulate memory pressure, implement shrinker callback | |
| Thu | `kfifo` - lockless ring buffer, `kfifo_in/out` | Producer/consumer with `kfifo`, measure latency | |
| Fri | `ida` (ID allocator), `xarray` (radix tree replacement) | Port `ida_simple_get` to userspace, test fragmentation | |
| Sat | **Mini-Project** | **Generic "Kernel DS Library" - compile as shared lib, test harness with 1M ops/sec benchmark** | Push: `libkernelds/` |
| Sun | Read: `Documentation/core-api/` list, hlist, kfifo, xarray, ida | | |

**Deliverable:** `libkernelds/` - userspace library mimicking kernel DS APIs with benchmarks

---

#### Week 4: Memory Allocation & Slab
**Goal:** `kmalloc`, `vmalloc`, `kmem_cache`, `__GFP_*` flags, slab debugging

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Buddy allocator, page orders, zones, `struct page` | Write kernel module: allocate orders 0-5, print `page_to_phys` | |
| Tue | `kmalloc` vs `vmalloc` vs `kzalloc`, `kmalloc_array` | Benchmark allocation latency, fragmentation | |
| Wed | Slab caches: `kmem_cache_create`, `SLAB_TYPESAFE_BY_RCU` | Create custom cache for your driver objects, objpool pattern | |
| Thu | Slub debug: `slub_debug=FZP`, `kmemleak`, `KASAN` | Enable KASAN, trigger use-after-free, double-free, analyze report | |
| Fri | `gen_pool` for special memory regions | Implement DMA coherent pool, test alignment | |
| Sat | **Mini-Project** | **Memory allocator stress test module: 10k threads, random sizes, verify no leaks with kmemleak** | Push: `mem-stress-module/` |
| Sun | Read: `mm/slub.c`, `mm/page_alloc.c`, `Documentation/vm/` | | |

**Deliverable:** `mem-stress-module/` - kernel module + userspace controller + KASAN/leak reports

---

#### Week 5: Concurrency Primitives (Locking)
**Goal:** Spinlocks, mutexes, rwlock, seqlock, RCU, completions, atomics

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Spinlock vs mutex: context rules, `_bh`, `_irq`, `_irqsave` | Kernel module: 4 CPUs hammering same lock, measure contention | |
| Tue | `rwlock` vs `rw_semaphore`, `seqlock` for read-mostly | Implement seqlock-protected timestamp, compare with rwlock | |
| Wed | RCU: `rcu_read_lock`, `call_rcu`, `srcu`, `rcu_barrier` | RCU-linked list with concurrent readers/writers, grace period trace | |
| Thu | Completions, waitqueues, `wait_event_interruptible` | Producer-consumer with completion signaling, measure wakeup latency | |
| Fri | Atomics: `atomic_t`, `atomic64_t`, `cmpxchg`, `refcount_t` | Implement lockless refcounted object, test with KCSAN | |
| Sat | **Mini-Project** | **Concurrency torture module: configurable contention, lockdep annotations, latency histogram via ftrace** | Push: `lock-torture/` |
| Sun | Read: `kernel/locking/`, `Documentation/locking/`, `Documentation/RCU/` | | |

**Deliverable:** `lock-torture/` - module with lockdep clean, ftrace-ready, benchmark suite

---

#### Week 6: Workqueues, Timers, Tasklets, Threaded IRQs
**Goal:** Bottom halves, deferrable work, kthread API, timer wheels

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Tasklets (deprecated) vs workqueues vs threaded IRQs | Convert tasklet → workqueue, measure latency difference | |
| Tue | `timer_list` vs `hrtimer` (high-res), `timer_setup` | Periodic vs one-shot, cancel safety, `del_timer_sync` | |
| Wed | `kthread` API: `kthread_create`, `kthread_run`, `kthread_stop` | Kernel thread that processes workqueue, graceful shutdown | |
| Thu | `delayed_work`, `schedule_delayed_work_on`, CPU affinity | Distribute work across CPUs, measure cache affinity | |
| Fri | `workqueue` attributes: `WQ_HIGHPRI`, `WQ_CPU_INTENSIVE`, `WQ_UNBOUND` | Custom workqueue for your driver, tune for latency vs throughput | |
| Sat | **Mini-Project** | **High-frequency sensor driver sim: threaded IRQ → workqueue → kthread → userspace via char dev, <100μs latency** | Push: `sensor-pipeline/` |
| Sun | Read: `kernel/workqueue.c`, `kernel/time/timer.c`, `Documentation/core-api/workqueue.rst` | | |

**Deliverable:** `sensor-pipeline/` - end-to-end latency measured, ftrace visualization

---

#### Week 7: Kernel Module Mastery & Kbuild
**Goal:** Professional module structure, Kconfig, Module.symvers, out-of-tree builds

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Module lifecycle: `init`/`exit`, `MODULE_*`, `EXPORT_SYMBOL*` | Multi-file module with proper header, `KBUILD_EXTRA_SYMBOLS` | |
| Tue | Kconfig: `config`, `tristate`, `depends on`, `select`, `default` | Add your module to kernel Kconfig, build as `m` and `y` | |
| Wed | `module_param`, `module_param_array`, `MODULE_PARM_DESC` | Userspace config via `/sys/module/.../parameters/` | |
| Thu | Out-of-tree build: `M=`, `KDIR=`, `ccflags-y`, `ldflags-y` | Build against 3 kernel versions (LTS, stable, mainline) | |
| Fri | Module signing: `CONFIG_MODULE_SIG`, `scripts/sign-file` | Sign module, boot with `module.sig_enforce=1` | |
| Sat | **Mini-Project** | **Professional driver template: Kconfig, Makefile, .c/.h, Documentation/, test/, CI (GitHub Actions)** | Push: `driver-template/` |
| Sun | Read: `Documentation/kbuild/`, `scripts/mod/`, `include/linux/module.h` | | |

**Deliverable:** `driver-template/` - cookiecutter for all future drivers, CI passes

---

#### Week 8: Char Driver Framework & Userspace ABI
**Goal:** `file_operations`, `cdev`, `device_class`, `ioctl`, `poll`, `mmap`, `fasync`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | `cdev_init`, `cdev_add`, `device_create`, `dev_t` allocation | Complete char driver with dynamic major, udev rules | |
| Tue | `ioctl` design: `_IO`, `_IOR`, `_IOW`, `_IOWR`, `_IOC_DIR`, compat | 10 ioctls with struct versioning, `_IOC_SIZE` validation | |
| Wed | `poll`/`select`/`epoll`: `poll_wait`, `wake_up_poll` | Event-driven userspace app, measure epoll latency | |
| Thu | `mmap`: `vm_operations_struct`, `remap_pfn_range`, `vm_insert_page` | Zero-copy buffer sharing kernel↔userspace, benchmark | |
| Fri | `fasync`: `fasync_helper`, `kill_fasync`, `F_SETFL` | Signal-driven I/O, compare with poll latency | |
| Sat | **Mini-Project** | **High-performance char driver: ring buffer (kfifo) + mmap + poll + ioctl config, 10GB/s throughput test** | Push: `char-driver-hp/` |
| Sun | Read: `fs/char_dev.c`, `include/linux/cdev.h`, `Documentation/driver-api/` | | |

**Deliverable:** `char-driver-hp/` - zero-copy, poll/mmap/ioctl, userspace lib + benchmark

---

### PHASE 2: PLATFORM DRIVERS & DEVICE TREE (Weeks 9-16)

#### Week 9: Driver Model & Platform Bus
**Goal:** `struct device_driver`, `platform_driver`, `probe`/`remove`, `pm_ops`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Driver core: `bus_type`, `device_register`, `driver_register` | Write minimal platform driver, trace probe order with ftrace | |
| Tue | `platform_device` vs `platform_driver`, `platform_device_id` | Match via ID table vs DT, `driver_override` sysfs | |
| Wed | Device lifecycle: `device_add` → `driver_probe_device` → `device_bind_driver` | Instrument probe sequence, measure boot time contribution | |
| Thu | PM domain: `dev_pm_ops`, `runtime_idle/suspend/resume`, `pm_runtime_*` | Implement runtime PM, verify with `pm_runtime_status` sysfs | |
| Fri | `managed` APIs: `devm_kmalloc`, `devm_ioremap`, `devm_request_irq` | Refactor driver to fully managed, test error path unwinding | |
| Sat | **Mini-Project** | **Platform driver framework: auto PM, managed resources, probe deferral handling, DT + non-DT support** | Push: `platform-driver-fw/` |
| Sun | Read: `drivers/base/`, `include/linux/platform_device.h`, `Documentation/driver-api/` | | |

---

#### Week 10: Device Tree (DT) Mastery
**Goal:** `.dts`/`.dtsi` syntax, bindings, overlays, `of_*` APIs, DT validation

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | DT syntax: nodes, properties, phandles, `#address-cells`, `#size-cells` | Write DT for fictional SoC: CPU, memory, 3 peripherals | |
| Tue | Bindings: `compatible`, `reg`, `interrupts`, `clocks`, `pinctrl`, `dma` | Write YAML binding (DT schema) for your platform driver | |
| Wed | `of_property_read_*`, `of_find_node_by_*`, `of_parse_phandle` | Parse complex DT: arrays, strings, phandle references | |
| Thu | DT overlays: `__overlay__`, `__fixups__`, `__symbols__`, `configfs` | Create runtime overlay for optional peripheral, apply via configfs | |
| Fri | DT validation: `dtc -@`, `dt_binding_check`, `make dtbs_check` | Validate your bindings, fix warnings, document in `Documentation/devicetree/bindings/` | |
| Sat | **Mini-Project** | **Complete DT ecosystem: .dtsi (SoC), .dts (board), bindings (yaml), driver using all `of_*` APIs, overlay demo** | Push: `dt-ecosystem/` |
| Sun | Read: `Documentation/devicetree/`, `scripts/dtc/`, `tools/ovl/` | | |

---

#### Week 11: I2C & SPI Subsystems
**Goal:** `i2c_driver`, `spi_driver`, `i2c_client`, `spi_device`, `regmap`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | I2C core: `i2c_algorithm`, `i2c_adapter`, `i2c_msg`, `i2c_transfer` | Write I2C driver for fake sensor (emulated in QEMU) | |
| Tue | SMBus vs I2C, `i2c_smbus_*`, `i2c_new_client_device` | Implement SMBus alerts, PEC, block reads | |
| Wed | SPI core: `spi_controller`, `spi_device`, `spi_message`, `spi_transfer_one` | SPI driver with DMA, multiple chip selects, CS GPIO | |
| Thu | **Regmap: `regmap_init_i2c/spi/mmio`, `regmap_read/write`, `regmap_update_bits`** | **Regmap-backed driver: cache, sync, async, interruptible regmap** | |
| Fri | Multi-byte transfers, `regmap_bulk_read`, `regmap_noinc_read` | FIFO burst reads, register cache sync on resume | |
| Sat | **Mini-Project** | **Real sensor driver (BMP280/MPU6050): I2C + regmap + IIO subsystem + DT binding + userspace tool** | Push: `i2c-sensor-driver/` |
| Sun | Read: `drivers/i2c/`, `drivers/spi/`, `drivers/base/regmap/`, `Documentation/i2c/` | | |

---

#### Week 12: GPIO, Pinctrl, Interrupts
**Goal:** `gpiochip`, `gpiod`, `pinctrl`, `irq_domain`, `irq_chip`, threaded IRQs

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | GPIO descriptor API: `gpiod_get`, `gpiod_direction_output`, `gpiod_set_value` | Consumer driver using `gpiod`, ACPI/DT lookup | |
| Tue | GPIO provider: `gpiochip_add_data`, `irqchip`, `gpiochip_irqchip_add` | Implement gpiochip for fake SoC, cascade to parent IRQ | |
| Wed | Pinctrl: `pinctrl_register`, `pinconf_generic`, `pinmux`, `pinctrl_dt_to_config` | DT pinctrl config: bias, drive, mux, group selection | |
| Thu | IRQ domain: `irq_domain_add_linear`, `irq_create_mapping`, `irq_chip` | Hierarchical IRQ domain: GPIO → parent GIC, measure latency | |
| Fri | Threaded IRQs: `request_threaded_irq`, `IRQF_ONESHOT`, `IRQF_NO_SUSPEND` | Primary handler (minimal) + threaded (bulk work), compare latency | |
| Sat | **Mini-Project** | **GPIO IRQ controller driver: 32 GPIOs, cascaded to GIC, pinctrl binding, consumer driver test** | Push: `gpio-irq-controller/` |
| Sun | Read: `drivers/gpio/`, `drivers/pinctrl/`, `drivers/irqchip/`, `Documentation/gpio/` | | |

---

#### Week 13: IIO (Industrial I/O) Subsystem
**Goal:** `iio_dev`, `iio_info`, `iio_buffer`, `iio_trigger`, `iio_map_array`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | IIO core: `iio_device_register`, `iio_channel`, `iio_buffer`, `iio_trigger` | Minimal IIO driver: 3 channels, sysfs interface | |
| Tue | Buffers: `iio_kfifo_allocate`, `iio_triggered_buffer`, `iio_pollfunc` | Continuous capture, userspace reads via `/dev/iio:deviceX` | |
| Wed | Triggers: `iio_trigger_alloc`, `iio_trigger_poll`, `iio_sysfs_trigger` | Hardware trigger (GPIO) + sysfs trigger, compare latency | |
| Thu | Event interface: `iio_event_spec`, `iio_push_event`, `iio_notify_event` | Threshold crossing events, userspace poll on `/dev/iio:deviceX` | |
| Fri | IIO mapping: `iio_map_array_register`, `iio_format_value` | Convert raw ADC → physical units (mV, °C, g) | |
| Sat | **Mini-Project** | **Complete IIO driver: ADC (8-ch) + DMA + hardware trigger + buffer + events + DT binding + libiio userspace** | Push: `iio-adc-driver/` |
| Sun | Read: `drivers/iio/`, `include/linux/iio/`, `Documentation/iio/` | | |

---

#### Week 14: USB Subsystem
**Goal:** `usb_driver`, `usb_interface`, `urb`, `usb_anchor`, `usb_sg_request`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | USB core: `usb_device`, `usb_interface`, `usb_endpoint`, `urb` lifecycle | USB skeleton driver: probe/disconnect, endpoint config | |
| Tue | URB types: control, bulk, interrupt, isochronous, `usb_submit_urb` | Bulk IN/OUT loopback test, measure throughput | |
| Wed | USB anchor: `usb_anchor_urb`, `usb_wait_anchor_empty_timeout` | Cancel all pending URBs on disconnect, no leaks | |
| Thu | usb_sg: scatter-gather for large transfers, `usb_sg_init` | 64KB scatter-gather transfer, compare with linear | |
| Fri | USB gadget (device mode): `usb_gadget`, `usb_function`, `configfs` | Implement CDC-ACM gadget, test with host PC | |
| Sat | **Mini-Project** | **USB bulk endpoint driver (host side): async URB queue, backpressure, 100MB/s sustained, userspace libusb test** | Push: `usb-bulk-driver/` |
| Sun | Read: `drivers/usb/core/`, `drivers/usb/gadget/`, `Documentation/usb/` | | |

---

#### Week 15: DMA Engine & DMABUF
**Goal:** `dmaengine`, `dma_chan`, `dma_async_tx`, `dma_buf`, `dma_heap`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | DMA API: `dma_map_single`, `dma_map_sg`, `dma_sync_*`, `dma_attrs` | Coherent vs streaming, cache sync, IOMMU awareness | |
| Tue | DMA Engine: `dmaengine_prep_*`, `dmaengine_submit`, `dma_async_issue_pending` | Memcpy via DMA engine, callback chaining, measure CPU offload | |
| Wed | Cyclic DMA: `dmaengine_prep_dma_cyclic`, `dmaengine_terminate_all` | Audio-style cyclic buffer, period callback, buffer management | |
| Thu | DMABUF: `dma_buf_export`, `dma_buf_attach`, `dma_buf_map_attachment` | Zero-copy share between two drivers (e.g., GPU → display) | |
| Fri | DMA heaps: `dma_heap_find`, `dma_heap_buffer_alloc`, `DMA_HEAP_IOCTL_ALLOC` | Allocate from `system` vs `cma` heap, compare fragmentation | |
| Sat | **Mini-Project** | **DMA pipeline: sensor → DMA engine → DMABUF → consumer driver, zero-copy, fence sync, <5% CPU** | Push: `dma-pipeline/` |
| Sun | Read: `drivers/dma/`, `drivers/dma-buf/`, `Documentation/dma-api/` | | |

---

#### Week 16: Clock, Regulator, Thermal, HWMon
**Goal:** `clk`, `regulator`, `thermal_zone`, `hwmon`, `sensor` subsystems

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Clock framework: `clk_register`, `clk_hw`, `clk_set_rate`, `clk_prepare_enable` | Clock tree: parent/child, rate propagation, DT `clocks` property | |
| Tue | Regulator framework: `regulator_register`, `regulator_set_voltage`, `regulator_enable` | PMIC driver: multiple rails, voltage constraints, DT binding | |
| Wed | Thermal: `thermal_zone_device_register`, `thermal_cooling_device_register` | CPU thermal zone + cooling device (freq limit), governor test | |
| Thu | HWMon: `hwmon_device_register`, `hwmon_chip_info`, `hwmon_ops` | Temperature/voltage/fan sensor driver, userspace `sensors` tool | |
| Fri | Integration: clk + regulator + thermal in one driver | Full PM sequence: clk enable → regulator on → thermal register | |
| Sat | **Mini-Project** | **PMIC driver: 4 regulators (buck/ldo), RTC, watchdog, ADC, GPIO, I2C + regmap + DT + hwmon + regulator + thermal** | Push: `pmic-driver/` |
| Sun | Read: `drivers/clk/`, `drivers/regulator/`, `drivers/thermal/`, `drivers/hwmon/` | | |

---

### PHASE 3: MEMORY MANAGEMENT & CONCURRENCY DEEP DIVE (Weeks 17-24)

#### Week 17: Page Allocator & Buddy System
**Goal:** `__alloc_pages`, `free_pages`, `alloc_contig_pages`, `CMA`, `migratetype`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Buddy allocator: `free_area`, `pageblock_order`, `MIGRATE_*` types | Trace `__alloc_pages_nodemask`, visualize free lists | |
| Tue | Page flags: `PG_*`, `PageBuddy`, `PageOffline`, `PageHuge` | `page_owner` debugging, find who allocated page | |
| Wed | CMA: `cma_alloc`, `cma_release`, `dma_declare_coherent_memory` | Reserve 64MB CMA, allocate/free under memory pressure | |
| Thu | `alloc_contig_pages` for huge physically contiguous buffers | 16MB contiguous allocation, compare with vmalloc | |
| Fri | Memory compaction: `compact_zone`, `migrate_pages`, `kcompactd` | Trigger compaction, measure latency, `compact_unevictable_allowed` | |
| Sat | **Mini-Project** | **Page allocator stress: 100 threads, mixed orders, CMA + movable + unmovable, verify no fragmentation** | Push: `page-alloc-stress/` |
| Sun | Read: `mm/page_alloc.c`, `mm/compaction.c`, `mm/cma.c`, `Documentation/vm/` | | |

---

#### Week 18: Slab Allocator (SLUB) Internals
**Goal:** `kmem_cache`, `slab`, `freelist`, `cpu_slab`, `kmem_cache_node`, debugging

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | SLUB design: page struct, freelist, `cpu_slab`, `partial` list | Trace `kmem_cache_alloc`, visualize per-cpu freelist | |
| Tue | Slab merging: `slab_mergeable`, `SLAB_RED_ZONE`, `SLAB_POISON` | Force merge/disable, measure memory overhead | |
| Wed | `kmem_cache_create` flags: `SLAB_TYPESAFE_BY_RCU`, `SLAB_ACCOUNT` | RCU-safe cache for lockless lookups, memcg accounting | |
| Thu | Slab debugging: `slub_debug=FZPU`, `kasan`, `kfence`, `kmemleak` | Inject bugs, verify detection, analyze reports | |
| Fri | `kmalloc` caches: `kmalloc-<size>`, `kmalloc-rcl-<size>`, `kmalloc-dma` | Custom cache vs kmalloc, benchmark allocation latency | |
| Sat | **Mini-Project** | **Custom slab cache for your driver objects: RCU-safe, memcg-aware, debug-instrumented, benchmark vs kmalloc** | Push: `custom-slab-cache/` |
| Sun | Read: `mm/slub.c`, `mm/slab.h`, `mm/kasan/`, `mm/kfence.c` | | |

---

#### Week 19: Virtual Memory & Page Tables
**Goal:** `vm_struct`, `vmap`, `ioremap`, `vmalloc`, `mmap`, `pfn`, `pte`, `pgd`, `p4d`, `pud`, `pmd`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Kernel virtual memory layout: `vmalloc`, `vmemmap`, `modules`, `kasan` | Map virtual → physical, walk page tables with `pgd_offset` | |
| Tue | `ioremap` vs `ioremap_cache` vs `ioremap_wc`, `memremap` | Map device registers, test cache attributes | |
| Wed | `vmalloc`/`vmap`: `vm_struct`, `vmap_area`, lazy TLB flush | Allocate 100MB vmalloc, compare with kmalloc | |
| Thu | User `mmap`: `vm_operations_struct`, `vm_fault`, `vm_page_mkwrite` | Implement `mmap` for your driver: fault, COW, writeback | |
| Fri | Page table walk: `pgd_offset`, `p4d_offset`, `pud_offset`, `pmd_offset`, `pte_offset` | Walk page tables for userspace address, modify PTE bits | |
| Sat | **Mini-Project** | **Userspace mmap driver: 1GB sparse mapping, on-demand page fault, hugepages (2MB/1GB), THP awareness** | Push: `mmap-driver/` |
| Sun | Read: `mm/vmalloc.c`, `mm/mmap.c`, `arch/*/mm/`, `Documentation/vm/` | | |

---

#### Week 20: RCU (Read-Copy-Update) Mastery
**Goal:** `rcu_read_lock`, `call_rcu`, `srcu`, `rcu_barrier`, `rcu_tasks`, grace periods

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | RCU fundamentals: grace period, quiescent state, `gp_seq`, `rcu_node` tree | Trace grace period with `rcutorture`, visualize callbacks | |
| Tue | `call_rcu` vs `call_rcu_tasks` vs `call_srcu`, `kfree_rcu` | RCU callback batching, measure callback latency | |
| Wed | RCU-protected data structures: `list_add_rcu`, `hlist_add_head_rcu`, `xarray` | RCU hash table with concurrent readers/writers, no locks | |
| Thu | RCU stall detection: `RCU_STALL_TIMEOUT`, `rcu_cpu_stall_suppress` | Force stall, analyze `rcu_dump_cpu_stacks` output | |
| Fri | `rcu_barrier`, `synchronize_rcu_expedited`, `rcu_read_unlock_strict` | Module unload with RCU: wait for all callbacks, no leaks | |
| Sat | **Mini-Project** | **Lockless cache: RCU-protected radix tree (xarray), 1M entries, 100k reads/sec, 1k writes/sec, zero locks** | Push: `rcu-lockless-cache/` |
| Sun | Read: `kernel/rcu/`, `Documentation/RCU/`, `kernel/rcu/rcutorture.c` | | |

---

#### Week 21: Locking Advanced & Lockdep
**Goal:** Lock classes, dependency chains, deadlock detection, `lockdep` annotations

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Lockdep: lock classes, `lockdep_register_key`, `lock_acquire`, `lock_release` | Enable `CONFIG_LOCKDEP`, trigger warning, analyze report | |
| Tue | Lock types: `raw_spinlock`, `spinlock`, `mutex`, `rw_sem`, `ww_mutex` | Cross-locking scenario: detect AB-BA deadlock | |
| Wed | Lock nesting: `lockdep_set_subclass`, `lockdep_set_novalidate` | Validated nested locking for your driver | |
| Thu | `lock_stat`: `CONFIG_LOCK_STAT`, contention tracking, `lock_contention` | Profile lock contention in your driver, optimize | |
| Fri | `lock_events`: `lock_contended`, `lock_acquired`, `lock_released` | Trace lock events with ftrace, visualize wait time | |
| Sat | **Mini-Project** | **Lockdep-clean driver suite: 5 drivers, complex locking, zero warnings, lock_stat dashboard** | Push: `lockdep-clean-drivers/` |
| Sun | Read: `kernel/locking/lockdep*.c`, `Documentation/locking/lockdep*.rst` | | |

---

#### Week 22: Memory Reclaim & Shrinkers
**Goal:** `shrink_slab`, `shrinker_register`, `vmscan`, `kswapd`, `lruvec`, `workingset`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | LRU lists: `active_anon`, `inactive_anon`, `active_file`, `inactive_file`, `unevictable` | Trace page reclaim with `trace_vmscan_*`, analyze scan/rotation | |
| Tue | Shrinker API: `shrinker_register`, `count_objects`, `scan_objects` | Implement shrinker for your custom cache, register with `list_lru` | |
| Wed | `kswapd`: `kswapd_run`, `balance_pgdat`, `pgdat_balanced` | Simulate memory pressure, watch kswapd wake/sleep | |
| Thu | Workingset: `workingset_refault`, `workingset_age_nonresident`, `thrashing` | Detect thrashing, tune `vm.swappiness`, `vm.vfs_cache_pressure` | |
| Fri | `memcg` reclaim: `mem_cgroup`, `page_counter`, hierarchical reclaim | Test memory limit on cgroup, verify reclaim behavior | |
| Sat | **Mini-Project** | **Memory pressure test suite: configurable pressure, shrinker stats, reclaim latency histogram, OOM simulation** | Push: `mem-reclaim-test/` |
| Sun | Read: `mm/vmscan.c`, `mm/workingset.c`, `mm/lru_gen.c`, `mm/memcontrol.c` | | |

---

#### Week 23: Concurrency Stress Testing (KCSAN, LKMM)
**Goal:** Data race detection, memory model, `CONFIG_KCSAN`, `litmus` tests

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Linux Kernel Memory Model (LKMM): `smp_mb`, `smp_rmb`, `smp_wmb`, `READ_ONCE`, `WRITE_ONCE` | Write litmus test for your locking pattern, run `herd7` | |
| Tue | KCSAN: `CONFIG_KCSAN`, `data_race`, `KCSAN_USE_ANALYSIS`, shadow memory | Enable KCSAN, run your driver stress test, analyze races | |
| Wed | Lockless patterns: `atomic_long_try_cmpxchg`, `refcount_inc_not_zero`, `cmpxchg` | Implement lockless stack, verify with KCSAN | |
| Thu | RCU + atomics: `atomic_long_add_return`, `rcu_assign_pointer`, `rcu_dereference` | RCU-protected pointer with atomic counters, no locks | |
| Fri | `READ_ONCE`/`WRITE_ONCE` vs `volatile`, compiler barriers | Audit your driver for missing `READ_ONCE`, fix | |
| Sat | **Mini-Project** | **Race-free driver audit: KCSAN clean, LKMM-verified, documented memory ordering for every shared variable** | Push: `race-free-driver/` |
| Sun | Read: `tools/memory-model/`, `Documentation/atomic*.rst`, `kernel/rcu/rcuhash.c` | | |

---

#### Week 24: Performance Analysis & Optimization
**Goal:** `perf`, `ftrace`, `eBPF`, `bpftool`, `CONFIG_PROFILE_ALL_BRANCHES`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | `perf record/report`: `perf.data`, call graphs, `--call-graph dwarf` | Profile your driver, find hot paths, cache misses | |
| Tue | `perf stat`: hardware counters (cycles, instructions, cache-misses, branch-misses) | Measure IPC, CPI, cache miss rate for your hot functions | |
| Wed | `ftrace` function_graph: `trace-cmd`, `kernelshark`, `ftrace_filter` | Trace full syscall path, find latency outliers | |
| Thu | eBPF: `bpftrace`, `bcc`, `bpftool`, CO-RE, `bpf_link` | Write bpftrace script for your driver's hot path | |
| Fri | GCC profiling: `-fprofile-generate`, `-fprofile-use`, `gcov`, `lcov` | Build kernel with PGO, measure improvement | |
| Sat | **Mini-Project** | **Full performance analysis: perf + ftrace + eBPF dashboard for your driver, 20% latency reduction** | Push: `perf-analysis/` |
| Sun | Read: `tools/perf/`, `tools/bpf/`, `kernel/trace/`, `Documentation/trace/` | | |

---

### PHASE 4: SUBSYSTEM DEEP DIVES (Weeks 25-32)

#### Week 25: Block Layer (request_queue, bio, elevator)
**Goal:** `request_queue`, `bio`, `request`, `blk_mq`, `elevator`, `blk_trace`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Block layer: `struct request_queue`, `blk_alloc_queue`, `blk_queue_*` | Minimal block driver (null_blk style), submit bio | |
| Tue | `blk_mq`: `blk_mq_init_queue`, `blk_mq_tag_set`, `blk_mq_ops` | Multi-queue block driver, hardware queue mapping | |
| Wed | Bio: `bio_alloc`, `bio_add_page`, `bio_vec`, `bvec_iter`, `submit_bio` | Bio chaining, integrity, `bio_integrity_add_page` | |
| Thu | I/O schedulers: `mq-deadline`, `kyber`, `bfq`, `none`, `elevator_switch` | Benchmark schedulers for your workload, tune parameters | |
| Fri | `blktrace`/`blkparse`/`btrace`: analyze I/O patterns, latency, merges | Trace your block driver, visualize with `btt`/`iowatcher` | |
| Sat | **Mini-Project** | **RAM-backed block device: blk-mq, 4 hardware queues, discard, write-zeroes, blktrace analysis** | Push: `block-driver/` |
| Sun | Read: `block/`, `drivers/block/`, `Documentation/block/` | | |

---

#### Week 26: Filesystem (VFS, inode, dentry, superblock)
**Goal:** `file_operations`, `inode_operations`, `dentry_operations`, `super_operations`, `address_space_operations`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | VFS: `struct file`, `struct inode`, `struct dentry`, `struct super_block` | Minimal read-only FS: mount, lookup, read | |
| Tue | `address_space`: `readpage`, `writepage`, `writepages`, `readpages`, `write_begin/end` | Page cache integration, `read_cache_page`, `mark_page_dirty` | |
| Wed | Dentry cache: `d_alloc`, `d_add`, `d_lookup`, `d_drop`, `d_invalidate` | Negative dentries, `dcache` tuning | |
| Thu | `iomap`/`buffered_io`/`direct_io`: `iomap_ops`, `iomap_file_buffered_write` | Modern I/O path vs legacy `buffer_head` | |
| Fri | Filesystem registration: `register_filesystem`, `fs_type`, `mount_bdev` | Register FS, mount via `mount -t yourfs`, sysfs `fs/` | |
| Sat | **Mini-Project** | **Simple FS: in-memory, persistent via block device, xattrs, ACLs, quotas, fsck** | Push: `simple-fs/` |
| Sun | Read: `fs/`, `include/linux/fs.h`, `Documentation/filesystems/` | | |

---

#### Week 27: Network Stack (sk_buff, net_device, NAPI)
**Goal:** `sk_buff`, `net_device`, `napi_struct`, `netif_receive_skb`, `XDP`, `tc`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | `sk_buff`: `skb_clone`, `skb_copy`, `pskb_expand_head`, `skb_linearize` | Packet manipulation, headroom/tailroom, fraglist | |
| Tue | `net_device`: `ndo_start_xmit`, `ndo_init`, `netdev_ops`, `ethtool_ops` | Virtual net driver (veth style), NAPI poll | |
| Wed | NAPI: `napi_enable`, `napi_schedule`, `napi_complete_done`, `gro` | NAPI poll budget, GRO coalescing, measure interrupt reduction | |
| Thu | XDP: `xdp_prog`, `bpf_xdp_attach`, `XDP_PASS/DROP/TX/REDIRECT` | XDP program for packet filter, redirect to userspace | |
| Fri | Traffic Control: `tc qdisc`, `clsact`, `flower`, `bpf` classifier | tc filter with eBPF, measure latency | |
| Sat | **Mini-Project** | **Virtual NIC driver: NAPI + GRO + XDP offload + ethtool stats + tc offload, 10Gbps line rate** | Push: `vnic-driver/` |
| Sun | Read: `net/core/`, `net/sched/`, `net/xdp/`, `Documentation/networking/` | | |

---

#### Week 28: GPU/DRM & DMA-BUF (Display Subsystem)
**Goal:** `drm_device`, `drm_driver`, `drm_crtc`, `drm_plane`, `drm_connector`, `drm_gem`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | DRM core: `drm_dev_register`, `drm_mode_config`, `drm_kms_helper` | Minimal DRM driver: virtual display, modeset | |
| Tue | GEM: `drm_gem_object`, `drm_gem_object_init`, `drm_prime` | Buffer sharing with DMABUF, `drm_gem_prime_import` | |
| Wed | Planes: `drm_plane`, `drm_plane_helper_funcs`, `drm_atomic` | Overlay plane, cursor, atomic commit, async flip | |
| Thu | Atomic modeset: `drm_atomic_state`, `drm_atomic_helper_*`, `drm_crtc_state` | Atomic commit with fence, non-blocking commit | |
| Fri | Debug: `drm_debugfs`, `drm_info`, `drm_error` | Debugfs interface for plane/crtc/connector state | |
| Sat | **Mini-Project** | **Virtual DRM driver: 2 planes + cursor, atomic modeset, DMABUF import/export, debugfs** | Push: `drm-virtual/` |
| Sun | Read: `drivers/gpu/drm/`, `include/drm/`, `Documentation/gpu/` | | |

---

#### Week 29: Interrupts & IRQ Affinity (Deep)
**Goal:** `irq_domain`, `irq_chip`, `irq_affinity`, `irq_affinity_hint`, `irq_set_affinity_hint`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | IRQ affinity: `irq_set_affinity`, `irq_affinity_hint`, `irq_can_set_affinity` | Pin IRQs to CPUs, measure cache locality | |
| Tue | MSI/MSI-X: `pci_enable_msi`, `pci_enable_msix`, `msi_domain` | Multiple vectors, per-CPU affinity, vector allocation | |
| Wed | IRQ threading: `request_threaded_irq`, `IRQF_NO_THREAD`, `IRQF_PERCPU` | Convert all handlers to threaded, measure latency | |
| Thu | IRQ chips: `irq_chip`, `irq_chip_ack`, `irq_chip_mask`, `irq_chip_set_affinity` | Custom IRQ chip for virtual interrupt controller | |
| Fri | Interrupt remapping: `IRQ_REMAP`, `intremap`, `iommu` | IOMMU interrupt remapping, isolation | |
| Sat | **Mini-Project** | **IRQ affinity optimizer: monitor /proc/interrupts, auto-balance based on load, per-queue RSS** | Push: `irq-affinity-optimizer/` |
| Sun | Read: `kernel/irq/`, `drivers/irqchip/`, `Documentation/IRQ-affinity.txt` | | |

---

#### Week 30: Power Management (Runtime PM, Suspend/Resume)
**Goal:** `dev_pm_ops`, `pm_runtime_*`, `system_pm`, `hibernate`, `cpuidle`, `cpufreq`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Runtime PM: `pm_runtime_enable`, `pm_runtime_get_sync`, `pm_runtime_put_autosuspend` | Auto-suspend timeout tuning, `power/control` sysfs | |
| Tue | System suspend: `suspend_prepare`, `suspend_enter`, `suspend_finish` | S2Idle vs Deep vs Hibernate, measure resume latency | |
| Wed | `cpuidle`: `cpuidle_driver`, `cpuidle_state`, `cpuidle_select` | C-states, residency measurement, `powertop` analysis | |
| Thu | `cpufreq`: `cpufreq_driver`, `cpufreq_policy`, governors (`schedutil`, `ondemand`) | Frequency scaling latency, energy per instruction | |
| Fri | `genpd` (power domains): `generic_pm_domain`, `pm_genpd_add_subdomain` | Hierarchical power domains, dependency management | |
| Sat | **Mini-Project** | **Power management test suite: runtime PM stress, suspend/resume latency histogram, energy measurement via RAPL** | Push: `pm-test-suite/` |
| Sun | Read: `drivers/base/power/`, `drivers/cpuidle/`, `drivers/cpufreq/`, `Documentation/power/` | | |

---

#### Week 31: Security (LSM, SELinux, AppArmor, TPM)
**Goal:** `security_operations`, `LSM`, `SELinux`, `integrity`, `IMA`, `EVM`, `TPM`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | LSM hooks: `security_file_open`, `security_inode_create`, `security_socket_connect` | Minimal LSM module: log all file opens | |
| Tue | SELinux: `avc_has_perm`, `selinux_enforcing`, `selinux_netlbl` | Write policy module, test with `audit2allow` | |
| Wed | IMA/EVM: `ima_appraise`, `evm_verify_hmac`, `security_integrity` | Enable IMA appraisal, measure boot time | |
| Thu | TPM 2.0: `tpm_chip`, `tpm_transmit`, `tpm_pcr_extend`, `tpm_pcr_read` | TPM driver for virtual TPM, PCR measurement log | |
| Fri | `lockdown`: `security_locked_down`, `LOCKDOWN_MODULE_SIGNATURE` | Test module signing enforcement, kexec lockdown | |
| Sat | **Mini-Project** | **LSM module: custom MAC policy for your driver objects, SELinux policy, IMA appraisal, TPM PCR logging** | Push: `security-lsm/` |
| Sun | Read: `security/`, `security/selinux/`, `security/integrity/`, `drivers/char/tpm/` | | |

---

#### Week 32: Real-Time (PREEMPT_RT, SCHED_DEADLINE)
**Goal:** `PREEMPT_RT`, `sched_dl`, `pi_futex`, `rt_mutex`, `irq_work`, `timerlat`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | PREEMPT_RT: `spinlock_t` → `rt_mutex`, `local_lock`, `preempt_count` | Build RT kernel, `cyclictest` baseline, identify latency sources | |
| Tue | SCHED_DEADLINE: `sched_attr`, `SCHED_DEADLINE`, `dl_runtime`, `dl_deadline`, `dl_period` | Real-time task with deadline, bandwidth enforcement | |
| Wed | Priority Inheritance: `rt_mutex`, `pi_state`, `futex_pi`, `PI_BOOST` | Mutex PI vs spinlock PI, measure inversion time | |
| Thu | `irq_work`: `irq_work_queue`, `irq_work_run`, `IRQ_WORK_HARD`/`SOFT` | Deferred work in IRQ context, compare with workqueue | |
| Fri | Latency tracing: `timerlat`, `osnoise`, `hwlat`, `trace_clock` | Measure timer, OS, hardware latency, correlate | |
| Sat | **Mini-Project** | **RT benchmark suite: cyclictest + osnoise + timerlat, RT kernel config tuning guide, 50μs max latency** | Push: `rt-benchmark/` |
| Sun | Read: `kernel/sched/`, `kernel/locking/rtmutex.c`, `kernel/time/timerlat.c` | | |

---

### PHASE 5: TESTING, TRACING, DEBUGGING (Weeks 33-40)

#### Week 33: KUnit & Kernel Selftests
**Goal:** `kunit`, `KUNIT_EXPECT_*`, `kunit_test_suite`, `kselftest`, `make kselftest`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | KUnit: `kunit_test`, `kunit_case`, `kunit_module_init` | Unit test for your driver's helper functions | |
| Tue | KUnit mocking: `kunit_action`, `kunit_resource`, `kunit_try_catch` | Mock `kmalloc`, `i2c_transfer`, `gpiod_get` | |
| Wed | `kselftest`: `tools/testing/selftests/`, `run_kselftest.sh` | Run all selftests, add test for your subsystem | |
| Thu | KUnit + kselftest integration: `kunit_tool`, `make kunit_test` | CI pipeline: build → boot → run KUnit → parse TAP | |
| Fri | Test coverage: `gcov`, `kcov`, `CONFIG_KCOV` | Measure line/branch coverage for your driver | |
| Sat | **Mini-Project** | **Complete test suite: KUnit (unit), kselftest (integration), 80% coverage, CI passes** | Push: `driver-test-suite/` |
| Sun | Read: `tools/testing/kunit/`, `tools/testing/selftests/`, `Documentation/dev-tools/kunit/` | | |

---

#### Week 34: eBPF for Observability (Advanced)
**Goal:** `bpftrace`, `bcc`, `libbpf`, `bpftool`, CO-RE, `bpf_link`, `fentry`/`fexit`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | eBPF verifier: `bpf_check`, `bpf_prog_load`, `bpf_map_create` | Write verifier-friendly BPF, analyze rejection log | |
| Tue | BPF maps: `BPF_MAP_TYPE_HASH`, `LRU_HASH`, `RINGBUF`, `PERF_EVENT_ARRAY`, `QUEUE` | Per-CPU histogram, ringbuf for events, map-in-map | |
| Wed | `fentry`/`fexit`/`fmod_ret`: attach to any kernel function, CO-RE | Trace any function without kprobes, BTF required | |
| Thu | `bpftool`: `prog dump`, `map dump`, `btf dump`, `gen` skeleton | Generate C skeleton from BTF, userspace loader | |
| Fri | `bpftrace` one-liners: `tracepoint:`, `kprobe:`, `usdt:`, `profile:hz` | Quick observability scripts for your driver | |
| Sat | **Mini-Project** | **eBPF observability stack: kernel driver + BPF program + userspace dashboard (Grafana), zero-code instrumentation** | Push: `ebpf-observability/` |
| Sun | Read: `kernel/bpf/`, `tools/bpf/`, `Documentation/bpf/` | | |

---

#### Week 35: Fault Injection & Chaos Testing
**Goal:** `fault_injection`, `fail_futex`, `failslab`, `fail_page_alloc`, `blk_dev_fail`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Fault injection framework: `failcmd`, `failslab`, `fail_page_alloc`, `fail_make_request` | Enable `failslab`, verify driver handles allocation failure | |
| Tue | `blk_dev_fail`: `make-it-fail`, `fail_request`, `fail_flush` | Inject block errors, verify retry/fallback | |
| Wed | `netdev_fail`: `fail_xmit`, `fail_receive` | Network packet drops, verify TCP recovery | |
| Thu | Custom fault points: `FAIL_POINT`, `fail_point_eval`, `fail_point_enable` | Add fault points to your driver, test error paths | |
| Fri | Chaos testing: `chaosmesh`, `krkn`, `litmus` | Random faults, verify system stability | |
| Sat | **Mini-Project** | **Fault injection test plan: 50 scenarios, automated, CI runs weekly, all error paths covered** | Push: `fault-injection-tests/` |
| Sun | Read: `lib/fault-inject.c`, `block/blk-fail.c`, `net/core/netdev-fail.c` | | |

---

#### Week 36: Live Patching & Kprobes
**Goal:** `klp`, `livepatch`, `kprobe`, `jprobe`, `kretprobe`, `kprobe_blacklist`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Live patching: `klp_patch`, `klp_object`, `klp_func`, `klp_init_apply` | Create live patch for your driver, test atomic replace | |
| Tue | `kprobe`/`kretprobe`: `register_kprobe`, `kprobe_opts`, `KPROBE_EVENT` | Trace function entry/exit/return, access arguments | |
| Wed | `kprobe` blacklist: `kprobe_blacklist`, `NOKPROBE_SYMBOL` | Protect critical functions, verify blacklist works | |
| Thu | `ftrace` + `kprobe`: `perf probe`, `trace_event_raw` | Dynamic tracing without rebuild | |
| Fri | `kpatch`/`kgraft` tools: userspace patch generation, `kpatch-build` | End-to-end: source change → patch → apply → verify | |
| Sat | **Mini-Project** | **Live patch demo: fix bug in your driver without reboot, verify with kprobe, document process** | Push: `livepatch-demo/` |
| Sun | Read: `kernel/livepatch/`, `kernel/kprobes.c`, `Documentation/livepatch/` | | |

---

#### Week 37: Debugging Production Issues
**Goal:** `crash`, `kdump`, `vmcore`, `kgdb`, `earlycon`, `magic_sysrq`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | `kdump`/`kexec`: `crashkernel=`, `makedumpfile`, `vmcore` analysis | Configure kdump, trigger panic, analyze vmcore | |
| Tue | `crash` utility: `bt`, `ps`, `kmem`, `files`, `irq`, `timer`, `log` | Post-mortem analysis of real panic | |
| Wed | `kgdb` over serial/net: `kgdboc`, `kgdbwait`, `earlycon` | Remote debug hanging kernel | |
| Thu | `magic_sysrq`: `sysrq_handle_*`, `sysrq_enabled` | SysRq-t, SysRq-m, SysRq-w, SysRq-s | |
| Fri | `objtool`/`pahole`: `CONFIG_DEBUG_INFO_BTF`, `pahole -C` | Analyze structure layout, BTF verification | |
| Sat | **Mini-Project** | **Debugging playbook: 10 real scenarios (panic, hang, leak, corruption), root cause analysis, fix validation** | Push: `debugging-playbook/` |
| Sun | Read: `Documentation/admin-guide/kdump/`, `Documentation/admin-guide/kgdb/`, `Documentation/admin-guide/sysrq.rst` | | |

---

#### Week 38: Continuous Integration & Kernel Testing
**Goal:** `gitlab-ci`/`github-actions`, `kernelci`, `0-day`, `lkp`, `syzbot`

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | Kernel CI: `kernelci.org`, `0-day`, `lkp-tests`, `syzbot` architecture | Submit your driver to 0-day bot, analyze report | |
| Tue | GitHub Actions: `make LL=1`, `clang-analyzer`, `sparse`, `coccinelle` | Static analysis pipeline, zero warnings | |
| Wed | `sparse`: `__bitwise`, `__force`, `CHECK_ENDIAN`, `noderef` | Annotate your driver with sparse annotations | |
| Thu | `coccinelle`: `spatch`, semantic patches, `scripts/coccinelle/` | Auto-fix coding style, API migrations | |
| Fri | `syzykaller`: fuzzing syscalls, `config.yaml`, `syz-manager` | Fuzz your driver's ioctl/mmap, find bugs | |
| Sat | **Mini-Project** | **CI pipeline: build (gcc/clang) → static analysis → KUnit → kselftest → syzkaller → deploy to test board** | Push: `kernel-ci-pipeline/` |
| Sun | Read: `tools/testing/selftests/`, `scripts/coccinelle/`, `Documentation/dev-tools/` | | |

---

#### Week 39: Documentation & Kernel Doc
**Goal:** `kernel-doc`, `Documentation/`, `sphinx`, `rst`, `gtk-doc`, `DeviceTree` bindings

| Day | Theory | Hands-on | Mini-Project |
|-----|--------|----------|--------------|
| Mon | `kernel-doc`: `/** ... */`, `@param`, `@return`, `@context`, `@lock` | Document all your driver's public functions | |
| Tue | `Documentation/`: `.rst`, `.. kernel-doc::`, `.. toctree::`, `make htmldocs` | Add driver documentation to `Documentation/driver-api/` | |
| Wed | Device Tree bindings: `yaml`, `jsonschema`, `dt_binding_check` | Write DT binding for your driver, validate | |
| Thu | `coccinelle` for docs: `spatch --doc` | Auto-generate docs from code | |
| Fri | `sphinx` extensions: `kernel-figure`, `kernel-c`, `kernel-symbol` | Build HTML/PDF docs locally, verify links | |
| Sat | **Mini-Project** | **Complete documentation package: kernel-doc, DT bindings, .rst, README, migration guide** | Push: `driver-docs/` |
| Sun | Read: `Documentation/`, `scripts/kernel-doc`, `Documentation/devicetree/bindings/` | | |

---

#### Week 40: Review & Gap Filling
**Goal:** Identify weak areas, consolidate, prepare for upstream

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Review all 39 weeks, rate confidence (1-5) per topic | Heatmap of strengths/weaknesses |
| Tue | Deep dive weakest 3 topics | Targeted exercises |
| Wed | Mock upstream submission: `checkpatch.pl`, `get_maintainer.pl`, cover letter | Dry-run submission |
| Thu | Read 50 recent LKML patches in your subsystem | Understand review patterns |
| Fri | Write 3 "dummy" patches for your driver (coding style, docs, minor fix) | Patch set ready |
| Sat | **Mock review session**: ask mentor/peer to review your patches | Feedback incorporated |
| Sun | Plan Weeks 41-52: target subsystems, maintainers, conferences | Roadmap finalized |

---

### PHASE 6: UPSTREAM CONTRIBUTION (Weeks 41-52)

#### Week 41: Subsystem Selection & Maintainer Research
**Goal:** Pick 3 target subsystems, understand maintainers, trees, processes

| Day | Activity | Output |
|-----|----------|--------|
| Mon | List your driver's subsystem(s): `get_maintainer.pl --norolestats drivers/your/driver.c` | Maintainer list, mailing lists, trees |
| Tue | Study maintainer's `Documentation/process/submitting-patches.rst` quirks | Checklist per maintainer |
| Wed | Clone maintainer's tree: `git remote add maint <url>`, `git fetch maint` | Local mirror of target tree |
| Thu | Read 100 recent commits in subsystem: `git log --oneline --since="6 months ago" -- drivers/your/subsystem/` | Patterns, style, common issues |
| Fri | Identify 5 "good first issues" or TODO comments in subsystem | Issue list with links |
| Sat | **Mini-Project** | **Subsystem guide: maintainers, trees, coding style, test requirements, review timeline** | Push: `subsystem-guide/` |
| Sun | Rest | |

---

#### Week 42: First Patch - Documentation/Trivial Fix
**Goal:** Merge first patch (doc, typo, comment, `checkpatch.pl` fix)

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Find doc typo / `checkpatch.pl` warning in your subsystem | Issue + fix |
| Tue | Write patch: `git format-patch -1`, proper commit message (subject, body, `Fixes:`, `Signed-off-by:`) | `.patch` file |
| Wed | Run `scripts/checkpatch.pl --strict --no-signoff your.patch` | Zero warnings |
| Thu | Run `scripts/get_maintainer.pl your.patch` | CC list |
| Fri | Send to self first: `git send-email --to=self --dry-run your.patch` | Verify formatting |
| Sat | **Send to LKML + maintainer** | Message-ID recorded |
| Sun | Track response, respond to reviews | Review feedback log |

---

#### Week 43: Second Patch - Code Improvement
**Goal:** Non-trivial code improvement (cleanup, warning fix, API modernization)

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Find `W=1` warning / sparse warning / TODO in subsystem | Candidate fix |
| Tue | Write fix, test build (all configs: `allyesconfig`, `allmodconfig`, `randconfig`) | Build log |
| Wed | KUnit test for fix, run `make kunit_test` | Test pass |
| Thu | `checkpatch.pl`, `get_maintainer.pl`, cover letter | Patch set |
| Fri | Send patch set (v1) | Message-ID |
| Sat | **Respond to review, send v2/v3 as needed** | Version iterations |
| Sun | Track to merge | Merge commit |

---

#### Week 44: Third Patch - New Feature/Functionality
**Goal:** Meaningful contribution (new sysfs attr, DT binding, error handling improvement)

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Design feature: discuss on mailing list first (`[RFC]` patch) | RFC feedback |
| Tue | Implement with full test coverage (KUnit + kselftest) | Code + tests |
| Wed | Documentation update (kernel-doc + .rst + DT binding) | Docs |
| Thu | Full test: `allyesconfig`, `allmodconfig`, `randconfig`, `clang`, `sparse`, `coccinelle` | Test matrix |
| Fri | Send `[PATCH v1]` series (cover letter + 3-5 patches) | Series |
| Sat | **Review cycle: v2, v3, v4... until merge** | Merge |
| Sun | Celebrate! Record in contribution log | |

---

#### Week 45: Sustained Contribution Rhythm
**Goal:** 1 patch/week average, build reputation

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Subsystem triage: review 5 patches from others, `Reply-to:`, `Tested-by:` | Review reputation |
| Tue | Write patch for issue from `todo` / `FIXME` / `XXX` | Patch |
| Wed | Test on hardware + QEMU + CI | Test report |
| Thu | Send patch | Sent |
| Fri | Respond to reviews on your patches | Reviews |
| Sat | **Weekly contribution log update** | Log |
| Sun | Rest / read LKML | |

---

#### Week 46: Conference & Community Engagement
**Goal:** Visibility, networking, learning

| Day | Activity |
|-----|----------|
| Mon | Register for Linux Plumbers / LPC / ELC / Kernel Summit |
| Tue | Submit talk proposal: "My driver journey" or technical deep-dive |
| Wed | Join subsystem mailing list discussions, ask/answer questions |
| Thu | IRC/Matrix: `#kernelnewbies`, `#linux-<subsystem>`, `#kernelci` |
| Fri | Find mentor via `kernel-mentors` mailing list |
| Sat | **Write blog post: "From student to kernel contributor"** |
| Sun | Rest |

---

#### Week 47: Advanced Subsystem Work
**Goal:** Tackle harder issues (performance, concurrency, architecture)

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Pick performance issue: `perf` analysis → root cause → fix | Perf patch |
| Tue | Concurrency bug: KCSAN race → LKMM analysis → fix | Race fix |
| Wed | Architecture support: add `arm64`/`riscv` support to your driver | Arch patch |
| Thu | Power management: runtime PM bug / suspend/resume fix | PM patch |
| Fri | Security: hardening / bounds check / lockdep annotation | Security patch |
| Sat | **Send 2-3 patches this week** | Sent |
| Sun | Rest |

---

#### Week 48: Maintainer Trust Building
**Goal:** Become "reliable contributor", get `Reviewed-by:` from maintainers

| Day | Activity |
|-----|----------|
| Mon-Fri | Review 10+ patches from others per week, high-quality reviews |
| | Test patches on your hardware, report results (`Tested-by:`) |
| | Fix nits in others' patches before maintainer sees them |
| | Help triage bugs in subsystem Bugzilla/GitHub |
| Sat | **Goal: 5 `Reviewed-by:` / `Tested-by:` credits this week** |
| Sun | Rest |

---

#### Week 49: Patch Series Mastery
**Goal:** Multi-patch series (5-10 patches) with proper bisectability

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Design series: logical splits, each patch compiles, bisectable | Patch plan |
| Tue | Implement series: 8 patches (prep, core, test, doc, cleanup) | 8 patches |
| Wed | `git rebase -i`, `git commit --fixup`, `git autosquash` | Clean history |
| Thu | Cover letter: `git format-patch --cover-letter`, series overview | Cover letter |
| Fri | Send series | Sent |
| Sat | **Manage review: v2-v5, split/merge patches as requested** | Merged |
| Sun | Rest |

---

#### Week 50: Regression Fixing & Stable Kernels
**Goal:** Fix regression, backport to stable

| Day | Activity | Output |
|-----|----------|--------|
| Mon | Monitor `linux-stable` mailing list, `git log --oneline -20 v6.x.y` | Stable queue |
| Tue | Find regression in your subsystem: `git bisect` | Bisect log |
| Wed | Fix regression, test on stable branch | Fix |
| Thu | Send to stable: `stable@vger.kernel.org` with `Cc: stable@vger.kernel.org` | Stable patch |
| Fri | Backport your feature to LTS (if applicable) | Backport |
| Sat | **Track: mainline + stable acceptance** | Log |
| Sun | Rest |

---

#### Week 51: Portfolio & Job Readiness
**Goal:** Professional showcase

| Day | Activity | Output |
|-----|----------|--------|
| Mon | GitHub portfolio: pin 5 best repos, detailed READMEs | Portfolio |
| Tue | Kernel contribution stats: `git shortlog -sn --all --grep="your@email"` | Stats page |
| Wed | Technical blog: 3 deep-dive posts on your patches | Blog |
| Thu | Resume: highlight kernel contributions, subsystems, metrics | Resume |
| Fri | Mock interview: kernel internals, your patches, debugging | Interview prep |
| Sat | **LinkedIn: connect with maintainers, kernel engineers** | Network |
| Sun | Rest |

---

#### Week 52: Graduation & Next Steps
**Goal:** Reflect, plan career

| Day | Activity |
|-----|----------|
| Mon | Review all 52 weeks: metrics (patches merged, lines changed, subsystems) |
| Tue | Write "Year in Review" blog post |
| Wed | Plan next 6 months: subsystem maintainership path, conference talks, mentoring |
| Thu | Apply to jobs: embedded Linux kernel engineer roles |
| Fri | Thank mentors, maintainers, community |
| Sat | **CELEBRATE! You're a kernel contributor.** |
| Sun | Rest |

---

## DAILY TIME BLOCK TEMPLATE

```
┌────────────────────────────────────────────────────────────────┐
│ 06:30-07:00  │ Morning: Review yesterday's notes, plan today    │
│ 07:00-08:00  │ Theory: Read kernel source / docs / LKML         │
│ 08:00-08:15  │ Break                                            │
│ 08:15-11:15  │ Hands-on: Code, test, debug (3 hrs, Pomodoro)    │
│ 11:15-11:30  │ Break                                            │
│ 11:30-12:00  │ Git: commit, format-patch, send-email practice   │
│ 12:00-13:00  │ Lunch / Walk                                     │
│ 13:00-14:00  │ Hands-on: Continue / Review / CI                 │
│ 14:00-14:30  │ Documentation: Update notes, kernel-doc, blog    │
│ 14:30-15:00  │ Community: LKML reading, review others' patches  │
│ 15:00        │ DONE - Rest of day free                          │
└────────────────────────────────────────────────────────────────┘
```

**Adjust hours to your schedule. Key: 3h solid coding block + 1h theory + 1h git/community.**

---

## TOOLING SETUP (Week 1, Day 1)

```bash
# ~/.bashrc additions
export KERNEL_SRC=~/linux
export ARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-
export PATH=$PATH:~/linux/scripts:/tools/bpf

# Git config for kernel
git config --global user.name "Your Name"
git config --global user.email "your@email.com"
git config --global format.signoff true
git config --global sendemail.smtpserver smtp.gmail.com
git config --global sendemail.smtpencryption tls
git config --global sendemail.smtpserverport 587

# Essential aliases
alias kbuild='make -j$(nproc) LL=1'
alias kcheck='./scripts/checkpatch.pl --strict --no-signoff'
alias kmaintainer='./scripts/get_maintainer.pl'
alias kcsan='make KCSAN=1'
alias kunit='./tools/testing/kunit/kunit.py run'
```

---

## PROGRESS TRACKING (Weekly)

```markdown
## Week XX: [Topic]
**Hours:** 35
**Commits:** X
**Lines Changed:** +X/-X
**Patches Sent:** X
**Patches Merged:** X
**Reviews Given:** X
**Tests Added:** X
**Coverage:** XX%
**Blockers:** [What slowed you down]
**Next Week Focus:** [Specific goals]
```

---

## RESOURCES (Curated)

| Category | Resources |
|----------|-----------|
| **Books** | "Linux Kernel Development" (Love), "Understanding the Linux Kernel" (Bovet), "Linux Device Drivers" (Corbet - free online) |
| **Docs** | `Documentation/process/`, `Documentation/core-api/`, `Documentation/driver-api/`, `Documentation/admin-guide/` |
| **Mailing Lists** | `linux-kernel@vger.kernel.org`, subsystem lists (e.g., `linux-i2c@vger.kernel.org`) |
| **Tools** | `checkpatch.pl`, `get_maintainer.pl`, `coccinelle`, `sparse`, `smatch`, `kunit_tool`, `bpftrace`, `perf`, `crash` |
| **Learning** | kernelnewbies.org, lwn.net (Kernel page), Linux Plumbers Conference videos, eBPF Summit videos |
| **Practice** | syzbot.appspot.com, kernelci.org, 0day.kernel.org, lkp.intel.com |

---

## SUCCESS METRICS (End of Year)

| Metric | Target |
|--------|--------|
| Patches merged to mainline | 15-25 |
| Subsystems touched | 3-5 |
| Lines of kernel code contributed | 2,000+ |
| `Reviewed-by:` / `Tested-by:` credits | 20+ |
| KUnit tests added | 10+ |
| Selftests added | 5+ |
| Documentation pages | 10+ |
| Conference talk submitted | 1 |
| Blog posts | 6+ |
| Job offers | 3+ |

---

## EMERGENCY PROTOCOLS

| Situation | Action |
|-----------|--------|
| Stuck on bug >2 days | Post to subsystem list with `[RFC]` or ask on `#kernelnewbies` |
| Burnout | Take 2 days off, read LWN.net instead of coding |
| Maintainer ignores patch | Wait 2 weeks, reply with `ping`, CC list maintainer |
| Rejection | Ask for clarification, address concerns, resend as v2 |
| Hardware bricked | Have spare SD card / JTAG / serial console ready |

---

*"The kernel community values persistence, code quality, and respectful communication over raw talent. Show up every day, write clean code, review others' work, and you will become a maintainer."*

**Start Date:** ___________  
**Week 1 Day 1:** ___________  
**First Patch Target Date:** ___________  

---

*Generated for: 2nd Year ECE Student | 5 hrs/day | Goal: Mainline Kernel Contributor*
*Based on analysis of your C_Practice repo showing strong C fundamentals and ATmega bare-metal experience*