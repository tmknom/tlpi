-include ../Makefile

cat: ## run cat
	$(call gcc,$(CURRENT_DIR)/cat.c)
	$(call exec,Makefile)

mmap: ## run mmap
	$(call gcc,$(CURRENT_DIR)/mmap.c)
	make run

anon: ## run anon
	$(call gcc,$(CURRENT_DIR)/anon.c)
	$(call exec)
