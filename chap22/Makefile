-include ../Makefile

sigqueue: ## run sigqueue
	$(call gcc,$(CURRENT_DIR)/sigqueue.c)
	$(call exec,1 54 100 3)

catch: ## run catch
	$(call gcc,$(CURRENT_DIR)/catch.c)
	make run

sigsuspend: ## run sigsuspend
	$(call gcc,$(CURRENT_DIR)/sigsuspend.c)
	$(call exec)

sigwaitinfo: ## run sigwaitinfo
	$(call gcc,$(CURRENT_DIR)/sigwaitinfo.c)
	$(call exec)

signalfd: ## run signalfd
	$(call gcc,$(CURRENT_DIR)/signalfd.c)
	$(call exec)
