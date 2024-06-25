all: up

up:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

clean:
	@docker stop $(shell docker ps -q)
	@docker container prune -f
	@docker image prune -af
	@docker volume prune -af
	@docker system prune -af
	@docker volume rm $(shell docker volume ls -q)

	sudo rm -rf /home/minseunk/data

.PHONY: up clean