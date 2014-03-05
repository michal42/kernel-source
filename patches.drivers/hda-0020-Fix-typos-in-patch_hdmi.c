From b55447a7301b12d509df4b2909ed38d125ad83d4 Mon Sep 17 00:00:00 2001
From: Takashi Iwai <tiwai@suse.de>
Date: Mon, 21 Oct 2013 16:31:45 +0200
Subject: [PATCH] ALSA: hda - Fix typos in patch_hdmi.c
Git-commit: b55447a7301b12d509df4b2909ed38d125ad83d4
Patch-mainline: 3.13-rc1
References: bnc#866937

... which was introduced by the previous commit a4e9a38b, causing
build errors without CONFIG_PROC_FS.

Reported-by: Fengguang Wu <fengguang.wu@intel.com>
Signed-off-by: Takashi Iwai <tiwai@suse.de>

---
 sound/pci/hda/patch_hdmi.c |    6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

--- a/sound/pci/hda/patch_hdmi.c
+++ b/sound/pci/hda/patch_hdmi.c
@@ -556,12 +556,12 @@ static void eld_proc_free(struct hdmi_sp
 	}
 }
 #else
-static inline int snd_hda_eld_proc_new(struct hdmi_spec_per_pin *per_pin,
-				       int index)
+static inline int eld_proc_new(struct hdmi_spec_per_pin *per_pin,
+			       int index)
 {
 	return 0;
 }
-static inline void snd_hda_eld_proc_free(struct hdmi_spec_per_pin *per_pin)
+static inline void eld_proc_free(struct hdmi_spec_per_pin *per_pin)
 {
 }
 #endif
