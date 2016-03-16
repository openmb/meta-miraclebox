SUMMARY = "Utilities for transponder & dvb-s blindscan"
SECTION = "base"
PRIORITY = "optional"
RDEPENDS_${PN} = "ncurses"

PACKAGE_ARCH = "${MACHINE_ARCH}"

LICENSE = "CLOSED"

PROVIDES += "virtual/blindscan-dvbc"
RPROVIDES_${PN} += "virtual/blindscan-dvbc"
PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES_${PN} += "virtual/blindscan-dvbs"

SRC_URI = "file://tda1002x file://ini_blindscan"

PV = "2.1"
PR = "r3"

S = "${WORKDIR}/"

FILES_miraclebox-blindscan-dvbs-utils = "${bindir}/*_blindscan"
FILES_miraclebox-blindscan-dvbc-utils = "${bindir}/tda1002x"
FILES_miraclebox-blindscan-dvbs-utils-dbg = "${bindir}/.debug/*_blindscan"
FILES_miraclebox-blindscan-dvbc-utils-dbg = "${bindir}/.debug/tda1002x"

do_install() {
    install -d ${D}/${bindir}/
    install -m 0755 "${S}/tda1002x" "${D}/${bindir}"
    install -m 0755 "${S}/ini_blindscan" "${D}/${bindir}"
}
