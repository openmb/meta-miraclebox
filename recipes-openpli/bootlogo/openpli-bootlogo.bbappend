PR = "r31"

do_install_append() {
	cp -a ${BRANDINGDIR}/recipes-openpli/bootlogo/files/bootlogo.mvi ${D}/usr/share/bootlogo.mvi
}
