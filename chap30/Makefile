-include ../Makefile

incr: ## run incr
	$(call gcc,$(CURRENT_DIR)/incr.c)
	$(call exec,1000)
	$(call exec,1000000)

mutex: ## run mutex
	$(call gcc,$(CURRENT_DIR)/mutex.c)
	$(call exec,1000)
	$(call exec,1000000)

multijoin: ## run multijoin
	$(call gcc,$(CURRENT_DIR)/multijoin.c)
	$(call exec,1 1 2 3 3)
