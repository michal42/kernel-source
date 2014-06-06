From: Alistair Popple <alistair@popple.id.au>
Subject: [PATCH] powerpc: Little endian sparse clean up for arch/powerpc/platforms/powernv/pci-ioda.c
Git-commit: c681b93c1fd016e94c8f3dd948dcc28a78790df7
Patch-mainline: v3.13-rc1
References: bnc#878240,FATE#315784,bnc#856774 fate#315275, LTC#92305

Signed-off-by: Alistair Popple <alistair@popple.id.au>
Signed-off-by: Benjamin Herrenschmidt <benh@kernel.crashing.org>
Acked-by: Torsten Duwe <duwe@suse.de>

diff --git a/arch/powerpc/platforms/powernv/pci-ioda.c b/arch/powerpc/platforms/powernv/pci-ioda.c
index 74a5a57..9a903ed 100644
--- a/arch/powerpc/platforms/powernv/pci-ioda.c
+++ b/arch/powerpc/platforms/powernv/pci-ioda.c
@@ -1106,7 +1106,7 @@ void __init pnv_pci_init_ioda_phb(struct device_node *np,
 	struct pci_controller *hose;
 	struct pnv_phb *phb;
 	unsigned long size, m32map_off, iomap_off, pemap_off;
-	const u64 *prop64;
+	const __be64 *prop64;
 	const u32 *prop32;
 	int len;
 	u64 phb_id;
@@ -1285,7 +1285,7 @@ void __init pnv_pci_init_ioda2_phb(struct device_node *np)
 void __init pnv_pci_init_ioda_hub(struct device_node *np)
 {
 	struct device_node *phbn;
-	const u64 *prop64;
+	const __be64 *prop64;
 	u64 hub_id;
 
 	pr_info("Probing IODA IO-Hub %s\n", np->full_name);
