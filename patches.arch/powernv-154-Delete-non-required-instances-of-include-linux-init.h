From: Paul Gortmaker <paul.gortmaker@windriver.com>
Subject: [PATCH] powerpc: Delete non-required instances of include <linux/init.h>
Git-commit: c141611fb1ee2cfc374cf9be5327e97f361c4bed
Patch-mainline: v3.14-rc1
References: bnc#878240,FATE#315784 

None of these files are actually using any __init type directives
and hence don't need to include <linux/init.h>.  Most are just a
left over from __devinit and __cpuinit removal, or simply due to
code getting copied from one driver to the next.

The one instance where we add an include for init.h covers off
a case where that file was implicitly getting it from another
header which itself didn't need it.

Signed-off-by: Paul Gortmaker <paul.gortmaker@windriver.com>
Signed-off-by: Benjamin Herrenschmidt <benh@kernel.crashing.org>
Acked-by: Torsten Duwe <duwe@suse.de>

Index: linux-3.12-SLE12/arch/powerpc/include/asm/paca.h
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/include/asm/paca.h
+++ linux-3.12-SLE12/arch/powerpc/include/asm/paca.h
@@ -16,7 +16,6 @@
 
 #ifdef CONFIG_PPC64
 
-#include <linux/init.h>
 #include <asm/types.h>
 #include <asm/lppaca.h>
 #include <asm/mmu.h>
Index: linux-3.12-SLE12/arch/powerpc/include/asm/ppc_asm.h
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/include/asm/ppc_asm.h
+++ linux-3.12-SLE12/arch/powerpc/include/asm/ppc_asm.h
@@ -4,7 +4,6 @@
 #ifndef _ASM_POWERPC_PPC_ASM_H
 #define _ASM_POWERPC_PPC_ASM_H
 
-#include <linux/init.h>
 #include <linux/stringify.h>
 #include <asm/asm-compat.h>
 #include <asm/processor.h>
Index: linux-3.12-SLE12/arch/powerpc/include/asm/ps3.h
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/include/asm/ps3.h
+++ linux-3.12-SLE12/arch/powerpc/include/asm/ps3.h
@@ -21,7 +21,6 @@
 #if !defined(_ASM_POWERPC_PS3_H)
 #define _ASM_POWERPC_PS3_H
 
-#include <linux/init.h>
 #include <linux/types.h>
 #include <linux/device.h>
 #include <asm/cell-pmu.h>
Index: linux-3.12-SLE12/arch/powerpc/include/asm/vio.h
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/include/asm/vio.h
+++ linux-3.12-SLE12/arch/powerpc/include/asm/vio.h
@@ -15,7 +15,6 @@
 #define _ASM_POWERPC_VIO_H
 #ifdef __KERNEL__
 
-#include <linux/init.h>
 #include <linux/errno.h>
 #include <linux/device.h>
 #include <linux/dma-mapping.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/cacheinfo.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/cacheinfo.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/cacheinfo.c
@@ -12,7 +12,6 @@
 
 #include <linux/cpu.h>
 #include <linux/cpumask.h>
-#include <linux/init.h>
 #include <linux/kernel.h>
 #include <linux/kobject.h>
 #include <linux/list.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/crash.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/crash.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/crash.c
@@ -17,7 +17,6 @@
 #include <linux/export.h>
 #include <linux/crash_dump.h>
 #include <linux/delay.h>
-#include <linux/init.h>
 #include <linux/irq.h>
 #include <linux/types.h>
 
Index: linux-3.12-SLE12/arch/powerpc/kernel/eeh_pe.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/eeh_pe.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/eeh_pe.c
@@ -25,7 +25,6 @@
 #include <linux/delay.h>
 #include <linux/export.h>
 #include <linux/gfp.h>
-#include <linux/init.h>
 #include <linux/kernel.h>
 #include <linux/pci.h>
 #include <linux/string.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/head_64.S
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/head_64.S
+++ linux-3.12-SLE12/arch/powerpc/kernel/head_64.S
@@ -23,6 +23,7 @@
  */
 
 #include <linux/threads.h>
+#include <linux/init.h>
 #include <asm/reg.h>
 #include <asm/page.h>
 #include <asm/mmu.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/hw_breakpoint.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/hw_breakpoint.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/hw_breakpoint.c
@@ -28,7 +28,6 @@
 #include <linux/percpu.h>
 #include <linux/kernel.h>
 #include <linux/sched.h>
-#include <linux/init.h>
 #include <linux/smp.h>
 
 #include <asm/hw_breakpoint.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/iomap.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/iomap.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/iomap.c
@@ -3,7 +3,6 @@
  *
  * (C) Copyright 2004 Linus Torvalds
  */
-#include <linux/init.h>
 #include <linux/pci.h>
 #include <linux/mm.h>
 #include <linux/export.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/kgdb.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/kgdb.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/kgdb.c
@@ -15,7 +15,6 @@
  */
 
 #include <linux/kernel.h>
-#include <linux/init.h>
 #include <linux/kgdb.h>
 #include <linux/smp.h>
 #include <linux/signal.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/process.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/process.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/process.c
@@ -25,7 +25,6 @@
 #include <linux/slab.h>
 #include <linux/user.h>
 #include <linux/elf.h>
-#include <linux/init.h>
 #include <linux/prctl.h>
 #include <linux/init_task.h>
 #include <linux/export.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/smp-tbsync.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/smp-tbsync.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/smp-tbsync.c
@@ -9,7 +9,6 @@
 #include <linux/sched.h>
 #include <linux/smp.h>
 #include <linux/unistd.h>
-#include <linux/init.h>
 #include <linux/slab.h>
 #include <linux/atomic.h>
 #include <asm/smp.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/syscalls.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/syscalls.c
+++ linux-3.12-SLE12/arch/powerpc/kernel/syscalls.c
@@ -34,7 +34,6 @@
 #include <linux/ipc.h>
 #include <linux/utsname.h>
 #include <linux/file.h>
-#include <linux/init.h>
 #include <linux/personality.h>
 
 #include <asm/uaccess.h>
Index: linux-3.12-SLE12/arch/powerpc/kernel/vdso32/vdso32_wrapper.S
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/vdso32/vdso32_wrapper.S
+++ linux-3.12-SLE12/arch/powerpc/kernel/vdso32/vdso32_wrapper.S
@@ -1,4 +1,3 @@
-#include <linux/init.h>
 #include <linux/linkage.h>
 #include <asm/page.h>
 
Index: linux-3.12-SLE12/arch/powerpc/kernel/vdso64/vdso64_wrapper.S
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/kernel/vdso64/vdso64_wrapper.S
+++ linux-3.12-SLE12/arch/powerpc/kernel/vdso64/vdso64_wrapper.S
@@ -1,4 +1,3 @@
-#include <linux/init.h>
 #include <linux/linkage.h>
 #include <asm/page.h>
 
Index: linux-3.12-SLE12/arch/powerpc/mm/pgtable.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/mm/pgtable.c
+++ linux-3.12-SLE12/arch/powerpc/mm/pgtable.c
@@ -24,7 +24,6 @@
 #include <linux/kernel.h>
 #include <linux/gfp.h>
 #include <linux/mm.h>
-#include <linux/init.h>
 #include <linux/percpu.h>
 #include <linux/hardirq.h>
 #include <linux/hugetlb.h>
Index: linux-3.12-SLE12/arch/powerpc/mm/pgtable_64.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/mm/pgtable_64.c
+++ linux-3.12-SLE12/arch/powerpc/mm/pgtable_64.c
@@ -33,7 +33,6 @@
 #include <linux/swap.h>
 #include <linux/stddef.h>
 #include <linux/vmalloc.h>
-#include <linux/init.h>
 #include <linux/bootmem.h>
 #include <linux/memblock.h>
 #include <linux/slab.h>
Index: linux-3.12-SLE12/arch/powerpc/mm/tlb_hash64.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/mm/tlb_hash64.c
+++ linux-3.12-SLE12/arch/powerpc/mm/tlb_hash64.c
@@ -23,7 +23,6 @@
 
 #include <linux/kernel.h>
 #include <linux/mm.h>
-#include <linux/init.h>
 #include <linux/percpu.h>
 #include <linux/hardirq.h>
 #include <asm/pgalloc.h>
Index: linux-3.12-SLE12/arch/powerpc/oprofile/op_model_7450.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/oprofile/op_model_7450.c
+++ linux-3.12-SLE12/arch/powerpc/oprofile/op_model_7450.c
@@ -16,7 +16,6 @@
  */
 
 #include <linux/oprofile.h>
-#include <linux/init.h>
 #include <linux/smp.h>
 #include <asm/ptrace.h>
 #include <asm/processor.h>
Index: linux-3.12-SLE12/arch/powerpc/oprofile/op_model_cell.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/oprofile/op_model_cell.c
+++ linux-3.12-SLE12/arch/powerpc/oprofile/op_model_cell.c
@@ -16,7 +16,6 @@
 
 #include <linux/cpufreq.h>
 #include <linux/delay.h>
-#include <linux/init.h>
 #include <linux/jiffies.h>
 #include <linux/kthread.h>
 #include <linux/oprofile.h>
Index: linux-3.12-SLE12/arch/powerpc/oprofile/op_model_fsl_emb.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/oprofile/op_model_fsl_emb.c
+++ linux-3.12-SLE12/arch/powerpc/oprofile/op_model_fsl_emb.c
@@ -14,7 +14,6 @@
  */
 
 #include <linux/oprofile.h>
-#include <linux/init.h>
 #include <linux/smp.h>
 #include <asm/ptrace.h>
 #include <asm/processor.h>
Index: linux-3.12-SLE12/arch/powerpc/oprofile/op_model_pa6t.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/oprofile/op_model_pa6t.c
+++ linux-3.12-SLE12/arch/powerpc/oprofile/op_model_pa6t.c
@@ -22,7 +22,6 @@
  */
 
 #include <linux/oprofile.h>
-#include <linux/init.h>
 #include <linux/smp.h>
 #include <linux/percpu.h>
 #include <asm/processor.h>
Index: linux-3.12-SLE12/arch/powerpc/oprofile/op_model_power4.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/oprofile/op_model_power4.c
+++ linux-3.12-SLE12/arch/powerpc/oprofile/op_model_power4.c
@@ -10,7 +10,6 @@
  */
 
 #include <linux/oprofile.h>
-#include <linux/init.h>
 #include <linux/smp.h>
 #include <asm/firmware.h>
 #include <asm/ptrace.h>
Index: linux-3.12-SLE12/arch/powerpc/oprofile/op_model_rs64.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/oprofile/op_model_rs64.c
+++ linux-3.12-SLE12/arch/powerpc/oprofile/op_model_rs64.c
@@ -8,7 +8,6 @@
  */
 
 #include <linux/oprofile.h>
-#include <linux/init.h>
 #include <linux/smp.h>
 #include <asm/ptrace.h>
 #include <asm/processor.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/83xx/mcu_mpc8349emitx.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/83xx/mcu_mpc8349emitx.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/83xx/mcu_mpc8349emitx.c
@@ -11,7 +11,6 @@
  * (at your option) any later version.
  */
 
-#include <linux/init.h>
 #include <linux/kernel.h>
 #include <linux/module.h>
 #include <linux/device.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/83xx/suspend.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/83xx/suspend.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/83xx/suspend.c
@@ -10,7 +10,6 @@
  * by the Free Software Foundation.
  */
 
-#include <linux/init.h>
 #include <linux/pm.h>
 #include <linux/types.h>
 #include <linux/ioport.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/85xx/sgy_cts1000.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/85xx/sgy_cts1000.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/85xx/sgy_cts1000.c
@@ -14,7 +14,6 @@
 #include <linux/platform_device.h>
 #include <linux/device.h>
 #include <linux/module.h>
-#include <linux/init.h>
 #include <linux/of_gpio.h>
 #include <linux/workqueue.h>
 #include <linux/reboot.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/chrp/smp.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/chrp/smp.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/chrp/smp.c
@@ -14,7 +14,6 @@
 #include <linux/interrupt.h>
 #include <linux/kernel_stat.h>
 #include <linux/delay.h>
-#include <linux/init.h>
 #include <linux/spinlock.h>
 
 #include <asm/ptrace.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/embedded6xx/hlwd-pic.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/embedded6xx/hlwd-pic.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/embedded6xx/hlwd-pic.c
@@ -15,7 +15,6 @@
 #define pr_fmt(fmt) DRV_MODULE_NAME ": " fmt
 
 #include <linux/kernel.h>
-#include <linux/init.h>
 #include <linux/irq.h>
 #include <linux/of.h>
 #include <linux/of_address.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/pasemi/dma_lib.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/pasemi/dma_lib.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/pasemi/dma_lib.c
@@ -18,7 +18,6 @@
  */
 
 #include <linux/kernel.h>
-#include <linux/init.h>
 #include <linux/export.h>
 #include <linux/pci.h>
 #include <linux/slab.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/powermac/pfunc_core.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/powermac/pfunc_core.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/powermac/pfunc_core.c
@@ -5,7 +5,6 @@
  * FIXME: LOCKING !!!
  */
 
-#include <linux/init.h>
 #include <linux/delay.h>
 #include <linux/kernel.h>
 #include <linux/spinlock.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/powernv/eeh-ioda.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/powernv/eeh-ioda.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/powernv/eeh-ioda.c
@@ -14,7 +14,6 @@
 #include <linux/bootmem.h>
 #include <linux/debugfs.h>
 #include <linux/delay.h>
-#include <linux/init.h>
 #include <linux/io.h>
 #include <linux/irq.h>
 #include <linux/kernel.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/pseries/cmm.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/pseries/cmm.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/pseries/cmm.c
@@ -25,7 +25,6 @@
 #include <linux/errno.h>
 #include <linux/fs.h>
 #include <linux/gfp.h>
-#include <linux/init.h>
 #include <linux/kthread.h>
 #include <linux/module.h>
 #include <linux/oom.h>
Index: linux-3.12-SLE12/arch/powerpc/platforms/pseries/dtl.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/platforms/pseries/dtl.c
+++ linux-3.12-SLE12/arch/powerpc/platforms/pseries/dtl.c
@@ -20,7 +20,6 @@
  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#include <linux/init.h>
 #include <linux/slab.h>
 #include <linux/debugfs.h>
 #include <linux/spinlock.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/cpm2_pic.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/cpm2_pic.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/cpm2_pic.c
@@ -27,7 +27,6 @@
  */
 
 #include <linux/stddef.h>
-#include <linux/init.h>
 #include <linux/sched.h>
 #include <linux/signal.h>
 #include <linux/irq.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/fsl_ifc.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/fsl_ifc.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/fsl_ifc.c
@@ -19,7 +19,6 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
-#include <linux/init.h>
 #include <linux/module.h>
 #include <linux/kernel.h>
 #include <linux/compiler.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/ge/ge_pic.h
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/ge/ge_pic.h
+++ linux-3.12-SLE12/arch/powerpc/sysdev/ge/ge_pic.h
@@ -1,7 +1,6 @@
 #ifndef __GEF_PIC_H__
 #define __GEF_PIC_H__
 
-#include <linux/init.h>
 
 void gef_pic_cascade(unsigned int, struct irq_desc *);
 unsigned int gef_pic_get_irq(void);
Index: linux-3.12-SLE12/arch/powerpc/sysdev/i8259.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/i8259.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/i8259.c
@@ -8,7 +8,6 @@
  */
 #undef DEBUG
 
-#include <linux/init.h>
 #include <linux/ioport.h>
 #include <linux/interrupt.h>
 #include <linux/kernel.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/mpc8xx_pic.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/mpc8xx_pic.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/mpc8xx_pic.c
@@ -1,6 +1,5 @@
 #include <linux/kernel.h>
 #include <linux/stddef.h>
-#include <linux/init.h>
 #include <linux/sched.h>
 #include <linux/signal.h>
 #include <linux/irq.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/qe_io.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/qe_lib/qe_io.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/qe_io.c
@@ -16,7 +16,6 @@
 
 #include <linux/stddef.h>
 #include <linux/kernel.h>
-#include <linux/init.h>
 #include <linux/errno.h>
 #include <linux/module.h>
 #include <linux/ioport.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/ucc.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/qe_lib/ucc.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/ucc.c
@@ -14,7 +14,6 @@
  * option) any later version.
  */
 #include <linux/kernel.h>
-#include <linux/init.h>
 #include <linux/errno.h>
 #include <linux/stddef.h>
 #include <linux/spinlock.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/ucc_fast.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/qe_lib/ucc_fast.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/ucc_fast.c
@@ -13,7 +13,6 @@
  * option) any later version.
  */
 #include <linux/kernel.h>
-#include <linux/init.h>
 #include <linux/errno.h>
 #include <linux/slab.h>
 #include <linux/stddef.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/ucc_slow.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/qe_lib/ucc_slow.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/qe_lib/ucc_slow.c
@@ -13,7 +13,6 @@
  * option) any later version.
  */
 #include <linux/kernel.h>
-#include <linux/init.h>
 #include <linux/errno.h>
 #include <linux/slab.h>
 #include <linux/stddef.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/udbg_memcons.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/udbg_memcons.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/udbg_memcons.c
@@ -18,7 +18,6 @@
  *      2 of the License, or (at your option) any later version.
  */
 
-#include <linux/init.h>
 #include <linux/kernel.h>
 #include <asm/barrier.h>
 #include <asm/page.h>
Index: linux-3.12-SLE12/arch/powerpc/sysdev/xics/icp-hv.c
===================================================================
--- linux-3.12-SLE12.orig/arch/powerpc/sysdev/xics/icp-hv.c
+++ linux-3.12-SLE12/arch/powerpc/sysdev/xics/icp-hv.c
@@ -12,7 +12,6 @@
 #include <linux/irq.h>
 #include <linux/smp.h>
 #include <linux/interrupt.h>
-#include <linux/init.h>
 #include <linux/cpu.h>
 #include <linux/of.h>
 
