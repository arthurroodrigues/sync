#include "sync_car.h"

void station_init(struct station *estacao)
{
	pthread_mutex_init(&estacao->trava, NULL);
	pthread_cond_init(&estacao->carro_chegou, NULL);
	pthread_cond_init(&estacao->todos_sentados, NULL);
	estacao->esperando = 0;
	estacao->assentos_livres = 0;
	estacao->embarcando = 0;
}

void station_wait_for_car(struct station *estacao)
{
	pthread_mutex_lock(&estacao->trava);
	estacao->esperando++;

	while (estacao->assentos_livres == 0)
		pthread_cond_wait(&estacao->carro_chegou, &estacao->trava);

	estacao->assentos_livres--;
	estacao->esperando--;
	estacao->embarcando++;
	pthread_mutex_unlock(&estacao->trava);
}

void station_on_board(struct station *estacao)
{
	pthread_mutex_lock(&estacao->trava);
	estacao->embarcando--;
	pthread_cond_signal(&estacao->todos_sentados);
	pthread_mutex_unlock(&estacao->trava);
}

void station_load_car(struct station *estacao, int count)
{
	pthread_mutex_lock(&estacao->trava);

	if (count == 0 || estacao->esperando == 0) {
		pthread_mutex_unlock(&estacao->trava);
		return;
	}

	estacao->assentos_livres = count;
	pthread_cond_broadcast(&estacao->carro_chegou);

	while ((estacao->esperando > 0 && estacao->assentos_livres > 0) ||
	       estacao->embarcando > 0)
		pthread_cond_wait(&estacao->todos_sentados, &estacao->trava);

	estacao->assentos_livres = 0;
	pthread_mutex_unlock(&estacao->trava);
}