MACHINE_KERNEL_PR = "r0"

KERNEL_MODULE_AUTOLOAD += "xfs"

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

IMAGE_CMD_ubi_prepend = " \
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS = "\
	${@base_contains("GST_VERSION", "1.0", "gstreamer1.0-libav", "gst-ffmpeg", d)} \
	miraclebox-dvb-modules-${MACHINE} \
	kernel-vmlinux \
	"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS = "\
	kernel-module-cdfs \
	"

MACHINE_EXTRA_RRECOMMENDS = " \
	gst-plugin-dvbmediasink \
	${@base_contains("MACHINE_FEATURES", "extrasplash", "miraclebox-cfe", "", d)} \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

TARGET_ARCH = "mipsel"
DEFAULTTUNE ?= "mips32el"

PREFERRED_PROVIDER_virtual/kernel = "linux-miraclebox"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "null"
SERIAL_CONSOLE ?= ""

IMAGE_FSTYPES ?= "ubi"

UBI_VOLNAME = "rootfs"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/cfe.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/splash.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/imageversion.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/kernel.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/rootfs.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/finished.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	cp ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.bin; \
	gzip -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/kernel.bin; \
	echo ${DISTRO_NAME}-${DISTRO_VERSION}-${DATE} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -Rf miraclebox; \
	"

MACHINE_FEATURES += "alsa usbhost wlan 3dtv switchoff osdposition hdmicec dvbusb bootsplash"

require conf/machine/include/tune-mips32.inc
require conf/machine/include/miraclebox-wifi.inc