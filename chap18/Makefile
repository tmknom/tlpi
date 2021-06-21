-include ../Makefile

unlink: ## run unlink
	$(call gcc,$(CURRENT_DIR)/unlink.c)
	$(call exec,/tmp/tfile 100000)

list: ## run list
	$(call gcc,$(CURRENT_DIR)/list.c)
	$(call exec,/work/chap18)
	$(call exec,/work)
