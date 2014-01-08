From: Philippe Bergheaud <felix@linux.vnet.ibm.com>
Subject: powerpc: Fix endian issue in setup-common.c
Git-commit: 01666c8ee2b6afcd31de2064fbb7c097a75e5089
Patch-mainline: v3.13-rc4
References: bnc#856774 fate#315275, LTC#92305

Summary:     powerpc: add little-endian support
Description: Add little-endian support for POWER8.

Upstream-Description:

    powerpc: Fix endian issue in setup-common.c

    During on LE boot we see:

        Partition configured for 1073741824 cpus, operating system maximum is 2048.

    Clearly missing a byteswap here.

Signed-off-by: Anton Blanchard <anton@samba.org>
Signed-off-by: Benjamin Herrenschmidt <benh@kernel.crashing.org>

Signed-off-by: Philippe Bergheaud <felix@linux.vnet.ibm.com>
Acked-by: Torsten Duwe <duwe@suse.de>
---
 arch/powerpc/kernel/setup-common.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/arch/powerpc/kernel/setup-common.c b/arch/powerpc/kernel/setup-common.c
index 3d261c0..14b5482 100644
--- a/arch/powerpc/kernel/setup-common.c
+++ b/arch/powerpc/kernel/setup-common.c
@@ -481,7 +481,7 @@ void __init smp_setup_cpu_maps(void)
 	if (machine_is(pseries) && firmware_has_feature(FW_FEATURE_LPAR) &&
 	    (dn = of_find_node_by_path("/rtas"))) {
 		int num_addr_cell, num_size_cell, maxcpus;
-		const unsigned int *ireg;
+		const __be32 *ireg;
 
 		num_addr_cell = of_n_addr_cells(dn);
 		num_size_cell = of_n_size_cells(dn);
@@ -491,7 +491,7 @@ void __init smp_setup_cpu_maps(void)
 		if (!ireg)
 			goto out;
 
-		maxcpus = ireg[num_addr_cell + num_size_cell];
+		maxcpus = be32_to_cpup(ireg + num_addr_cell + num_size_cell);
 
 		/* Double maxcpus for processors which have SMT capability */
 		if (cpu_has_feature(CPU_FTR_SMT))
-- 
1.8.3.1

