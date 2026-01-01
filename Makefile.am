SUBDIRS = src 

test:
	(cd check && ./check.sh)


deb:
	$(MAKE) install DESTDIR=$(abs_top_builddir)/debian-package
	mkdir -p $(abs_top_builddir)/debian-package/DEBIAN
	cp  $(abs_top_builddir)/debpostinst $(abs_top_builddir)/debian-package/DEBIAN/postinst
	@echo "Package: $(PACKAGE)" > $(abs_top_builddir)/debian-package/DEBIAN/control
	@echo "Version: $(VERSION)" >> $(abs_top_builddir)/debian-package/DEBIAN/control
	@echo "Section: base" >> $(abs_top_builddir)/debian-package/DEBIAN/control
	@echo "Priority: optional" >> $(abs_top_builddir)/debian-package/DEBIAN/control
	@echo "Architecture: $$(dpkg --print-architecture)" >> $(abs_top_builddir)/debian-package/DEBIAN/control
	@echo "Maintainer: $(USER) <$(USER)@example.com>" >> $(abs_top_builddir)/debian-package/DEBIAN/control
	@echo "Description: $(PACKAGE) summary" >> $(abs_top_builddir)/debian-package/DEBIAN/control
	@echo "  Detailed description of $(PACKAGE)" >> $(abs_top_builddir)/debian-package/DEBIAN/control
	dpkg-deb --build $(abs_top_builddir)/debian-package $(PACKAGE)_$(VERSION)_$$(dpkg --print-architecture).deb
	rm -rf $(abs_top_builddir)/debian-package
	