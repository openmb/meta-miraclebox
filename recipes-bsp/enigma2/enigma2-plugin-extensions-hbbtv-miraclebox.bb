DESCRIPTION = "Miraclebox HbbTv"
LICENSE = "GPLv2"
PACKAGE_ARCH = "${MACHINE_ARCH}"

LIC_FILES_CHKSUM = "file://README.md;md5=4a881119de8945a8b2ca1da5e5ca1f58"

SRC_URI = "file://enigma2-plugin-extensions-hbbtv-miraclebox.tar.gz"

inherit gitpkgv

PR = "r1"

SRCREV = "${AUTOREV}"

FILES_${PN} = "/usr"

INHIBIT_PACKAGE_STRIP = "1"

ALLOW_EMPTY_${PN} = "1"

S="${WORKDIR}/usr"

do_install() {
	install -d ${D}/usr
	cp -a ${S}/usr/* ${D}/usr/
}