-include ../Makefile

mem: ## run mem
	$(call gcc,$(CURRENT_DIR)/mem.c)
	$(call exec)

necho: ## run necho
	$(call gcc,$(CURRENT_DIR)/necho.c)
	$(call exec,)
	$(call exec,foo bar)

display_env: ## run display_env
	$(call gcc,$(CURRENT_DIR)/display_env.c)
	$(call exec)

modify_env: ## run modify_env
	$(call gcc,$(CURRENT_DIR)/modify_env.c)
	$(call exec,GREET=foo SHELL=/bin/bash BYE=Ciao)
	$(call exec,SHELL=/bin/sh BYE=byebye)
