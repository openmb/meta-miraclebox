SUMMARY = "Utilities for transponder & dvb-s blindscan"
SECTION = "base"
PRIORITY = "optional"
RDEPENDS_${PN} = "ncurses"
LICENSE = "CLOSED"

PACKAGES = "miraclebox-blindscan-dvbs-utils-${MACHINE} miraclebox-blindscan-dvbc-utils-${MACHINE}"

PROVIDES += "virtual/blindscan-dvbs virtual/blindscan-dvbc"
RPROVIDES_miraclebox-blindscan-dvbs-utils-${MACHINE} += "virtual/blindscan-dvbs"
RPROVIDES_miraclebox-blindscan-dvbc-utils-${MACHINE} += "virtual/blindscan-dvbc"

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
