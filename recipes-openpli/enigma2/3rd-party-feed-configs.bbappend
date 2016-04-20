do_compile_append() {
    [ ! -d ${S}/${sysconfdir}/opkg ] && mkdir -p ${S}/${sysconfdir}/opkg
    echo "src/gz openpli-3rd-party4 http://downloads.pli-images.org/feeds/openpli-4/3rd-party" > ${S}/${sysconfdir}/opkg/3rd-partypli4-feed.conf
    echo "src/gz openpli-3rd-party5 http://downloads.pli-images.org/feeds/openpli-5/3rd-party" > ${S}/${sysconfdir}/opkg/3rd-partypli5-feed.conf
    echo "src/gz openpli-3rdpartyatv http://feeds2.mynonpublic.com/5.3/g300/3rdparty" > ${S}/${sysconfdir}/opkg/3rdpartyatv-feed.conf
}
