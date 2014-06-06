From: Alistair Popple <alistair@popple.id.au>
Subject: [PATCH] powerpc: Little endian fixes for platforms/powernv/opal.c
Git-commit: 1cc79bc80606229b0e7e56c76ee3cb3594409aa9
Patch-mainline: v3.13-rc1
References: bnc#878240,FATE#315784 

Signed-off-by: Alistair Popple <alistair@popple.id.au>
Signed-off-by: Benjamin Herrenschmidt <benh@kernel.crashing.org>
Acked-by: Torsten Duwe <duwe@suse.de>

diff --git a/arch/powerpc/platforms/powernv/opal.c b/arch/powerpc/platforms/powernv/opal.c
index 2911abe..4ffa75e 100644
--- a/arch/powerpc/platforms/powernv/opal.c
+++ b/arch/powerpc/platforms/powernv/opal.c
@@ -372,7 +372,7 @@ static irqreturn_t opal_interrupt(int irq, void *data)
 static int __init opal_init(void)
 {
 	struct device_node *np, *consoles;
-	const u32 *irqs;
+	const __be32 *irqs;
 	int rc, i, irqlen;
 
 	opal_node = of_find_node_by_path("/ibm,opal");
