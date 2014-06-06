From: Alistair Popple <alistair@popple.id.au>
Subject: [PATCH] powerpc: Little endian fix for arch/powerpc/platforms/powernv/pci-p5ioc2.c
Git-commit: 8c5fcc83afd0738a089641bc0862b9058e9cfd06
Patch-mainline: v3.13-rc1
References: bnc#878240,FATE#315784,bnc#856774 fate#315275, LTC#92305

Signed-off-by: Alistair Popple <alistair@popple.id.au>
Signed-off-by: Benjamin Herrenschmidt <benh@kernel.crashing.org>
Acked-by: Torsten Duwe <duwe@suse.de>

diff --git a/arch/powerpc/platforms/powernv/pci-p5ioc2.c b/arch/powerpc/platforms/powernv/pci-p5ioc2.c
index b68db63..f8b4bd8 100644
--- a/arch/powerpc/platforms/powernv/pci-p5ioc2.c
+++ b/arch/powerpc/platforms/powernv/pci-p5ioc2.c
@@ -99,7 +99,7 @@ static void __init pnv_pci_init_p5ioc2_phb(struct device_node *np, u64 hub_id,
 					   void *tce_mem, u64 tce_size)
 {
 	struct pnv_phb *phb;
-	const u64 *prop64;
+	const __be64 *prop64;
 	u64 phb_id;
 	int64_t rc;
 	static int primary = 1;
@@ -178,7 +178,7 @@ static void __init pnv_pci_init_p5ioc2_phb(struct device_node *np, u64 hub_id,
 void __init pnv_pci_init_p5ioc2_hub(struct device_node *np)
 {
 	struct device_node *phbn;
-	const u64 *prop64;
+	const __be64 *prop64;
 	u64 hub_id;
 	void *tce_mem;
 	uint64_t tce_per_phb;
