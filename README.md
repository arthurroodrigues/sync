# Sincronização do Metrô (sync_car)

Implementação 4 de Infraestrutura de Software (CESAR School). Sincronização entre carro e passageiros de uma estação de metrô, usando threads POSIX com um mutex e variáveis de condição.

## Sistema operacional

Desenvolvido e testado em Ubuntu (WSL no Windows). Funciona em Linux, Unix e macOS.

## Arquivos

- `sync_car.h`: define a `struct station` e declara as quatro funções.
- `sync_car.c`: implementa `station_init`, `station_load_car`, `station_wait_for_car` e `station_on_board`.
- `sync_car-runner.c`: programa de teste fornecido pelo professor, que simula o carro e 100 passageiros em threads. Não foi modificado.
- `Makefile`: compila e limpa os arquivos gerados.
- `evidencias.log`: registro do terminal (`script -a`) com compilação e testes.

## Como compilar

```
make
```

Gera o executável `sync_car`. O compilador mostra um aviso de parâmetro não usado (`foo`) em `sync_car-runner.c`. Ele vem do código de teste, e não afeta o funcionamento.

Para apagar os arquivos gerados:

```
make clean
```

## Como executar e testar

```
./sync_car
```

O runner faz carros com número aleatório de assentos passarem pela estação até os 100 passageiros embarcarem. A saída esperada termina com:

```
Looks good!
```

Para repetir o teste várias vezes e detectar falhas intermitentes:

```
for i in $(seq 100); do ./sync_car | tail -1; done | sort | uniq -c
```

O esperado é `100 Looks good!`.
