-include ../Makefile

writer: ## run writer
	$(call gcc,$(CURRENT_DIR)/writer.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svshm_writer

reader: writer ## run reader
	$(call gcc,$(CURRENT_DIR)/writer.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svshm_reader
	make run
