From: Alistair Popple <alistair@popple.id.au>
Subject: [PATCH] powerpc: Little endian fix for arch/powerpc/platforms/powernv/pci.c
Git-commit: 044cb69c53f286673b6809641f9c0ce929f9f221
Patch-mainline: v3.13-rc1
References: bnc#878240,FATE#315784 

Signed-off-by: Alistair Popple <alistair@popple.id.au>
Signed-off-by: Benjamin Herrenschmidt <benh@kernel.crashing.org>
Acked-by: Torsten Duwe <duwe@suse.de>

diff --git a/arch/powerpc/platforms/powernv/pci.c b/arch/powerpc/platforms/powernv/pci.c
index a28d3b5..9122215 100644
--- a/arch/powerpc/platforms/powernv/pci.c
+++ b/arch/powerpc/platforms/powernv/pci.c
@@ -462,8 +462,8 @@ void pnv_pci_setup_iommu_table(struct iommu_table *tbl,
 static struct iommu_table *pnv_pci_setup_bml_iommu(struct pci_controller *hose)
 {
 	struct iommu_table *tbl;
-	const __be64 *basep, *swinvp;
-	const __be32 *sizep;
+	const __be64 *basep;
+	const __be32 *sizep, *swinvp;
 
 	basep = of_get_property(hose->dn, "linux,tce-base", NULL);
 	sizep = of_get_property(hose->dn, "linux,tce-size", NULL);
@@ -484,8 +484,9 @@ static struct iommu_table *pnv_pci_setup_bml_iommu(struct pci_controller *hose)
 	swinvp = of_get_property(hose->dn, "linux,tce-sw-invalidate-info",
 				 NULL);
 	if (swinvp) {
-		tbl->it_busno = swinvp[1];
-		tbl->it_index = (unsigned long)ioremap(swinvp[0], 8);
+		tbl->it_busno = of_read_ulong(&swinvp[1], 2);
+		tbl->it_index =
+			(unsigned long)ioremap(of_read_number(swinvp, 2), 8);
 		tbl->it_type = TCE_PCI_SWINV_CREATE | TCE_PCI_SWINV_FREE;
 	}
 	return tbl;
