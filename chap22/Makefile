-include ../Makefile

sigqueue: ## run sigqueue
	$(call gcc,$(CURRENT_DIR)/sigqueue.c)
	$(call exec,1 54 100 3)

catch: ## run catch
	$(call gcc,$(CURRENT_DIR)/catch.c)
	make run
