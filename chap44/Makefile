-include ../Makefile

pipe: ## run pipe
	$(call gcc,$(CURRENT_DIR)/pipe.c)
	$(call exec,'This is a pen. This is an apple.')

sync: ## run sync
	$(call gcc,$(CURRENT_DIR)/sync.c)
	$(call exec,2 4 6)

lswc: ## run lswc
	$(call gcc,$(CURRENT_DIR)/lswc.c)
	$(call exec)

glob: ## run glob
	$(call gcc,$(CURRENT_DIR)/glob.c)
	$(call exec)

fifo: ## run fifo
	$(call gcc,$(CURRENT_DIR)/fifo_server.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/fifo_server
	$(call gcc,$(CURRENT_DIR)/fifo_client.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/fifo_client
	make run
