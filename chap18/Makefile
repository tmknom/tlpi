-include ../Makefile

unlink: ## run unlink
	$(call gcc,$(CURRENT_DIR)/unlink.c)
	$(call exec,/tmp/tfile 100000)

list: ## run list
	$(call gcc,$(CURRENT_DIR)/list.c)
	$(call exec,/work/chap18)
	$(call exec,/work)

nftw: ## run nftw
	$(call gcc,$(CURRENT_DIR)/nftw.c)
	$(call exec,/work/chap18)

symlink: ## run symlink
	$(call gcc,$(CURRENT_DIR)/symlink.c)
	make run

basename: ## run basename
	$(call gcc,$(CURRENT_DIR)/basename.c)
	$(call exec,/work/chap18/Makefile)
