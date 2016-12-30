MACHINE_KERNEL_PR = "r0"

KERNEL_MODULE_AUTOLOAD += "xfs"

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

IMAGE_CMD_ubi_prepend = " \
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS = "\
	${@bb.utils.contains("GST_VERSION", "1.0", "gstreamer1.0-libav", "gst-ffmpeg", d)} \
	miraclebox-dvb-modules-${MACHINE} \
	kernel-vmlinux \
	"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS = "\
	kernel-module-cdfs \
	"

MACHINE_EXTRA_RRECOMMENDS = " \
	gst-plugin-dvbmediasink \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "miraclebox-cfe", "", d)} \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

TARGET_ARCH = "mipsel"
DEFAULTTUNE ?= "mips32el"

PREFERRED_PROVIDER_virtual/kernel = "linux-${MACHINE}"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "miraclebox-blindscan-utils-${MACHINE}"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "miraclebox-blindscan-utils-${MACHINE}"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_OUTPUT_DIR = "."
KERNEL_CONSOLE = "null"
SERIAL_CONSOLE ?= ""

IMAGE_FSTYPES ?= "ubi"

UBI_VOLNAME = "rootfs"

IMGDEPLOYDIR ?= "${DEPLOY_DIR_IMAGE}"
IMAGEVERSION := "${DISTRO_NAME}-${DISTRO_VERSION}-${DATE}"
IMAGEVERSION[vardepsexclude] = "DATE"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${IMGDEPLOYDIR}/${IMAGEDIR}; \
	cp ${IMGDEPLOYDIR}/${IMAGE_NAME}.rootfs.ubi ${IMGDEPLOYDIR}/${IMAGEDIR}/rootfs.bin; \
	gzip -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${IMGDEPLOYDIR}/${IMAGEDIR}/kernel.bin; \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/splash.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/cfe.bmp ${IMGDEPLOYDIR}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/splash.bmp ${IMGDEPLOYDIR}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/imageversion.bmp ${IMGDEPLOYDIR}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/kernel.bmp ${IMGDEPLOYDIR}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/rootfs.bmp ${IMGDEPLOYDIR}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/finished.bmp ${IMGDEPLOYDIR}/${IMAGEDIR}/;" , "", d)} \
	echo "${IMAGEVERSION}" > ${IMGDEPLOYDIR}/${IMAGEDIR}/imageversion; \
	echo "rename this file to 'force' to force an update without confirmation" > ${IMGDEPLOYDIR}/${IMAGEDIR}/noforce; \
	cd ${IMGDEPLOYDIR}; \
	zip ${DISTRO_NAME}-${DISTRO_VERSION}-${MACHINE}-${DATE}_usb.zip ${IMAGEDIR}/*; \
	rm -Rf ${IMAGEDIR}; \
	"

IMAGE_CMD_ubi_prepend = " \
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	"

MACHINE_FEATURES += "alsa usbhost wlan 3dtv switchoff osdposition hdmicec dvbusb"

require conf/machine/include/tune-mips32.inc
require conf/machine/include/miraclebox-wifi.inc
