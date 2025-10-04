# so_long

## Descrição
So_long é um dos três primeiros projetos gráficos da 42, eu escolhi por ter mais afinidade e gosto por jogo, ele consiste em fazer uma representação gráfica de um jogo 2D. O objetivo do projeto é ser jogável, para isso temos que garantir que o personagem tenha pelo menos um caminho válido para pegar todos os coletáveis e liberar a saída.

## Sumário
- [Recursos](#recursos)
- [Instalação](#instalação)
- [Uso](#uso)

## Recursos
- Contador de movimentos (passos) do jogador.
- Diferentes sprites pro chão (0), parede (1), Personagem (P), Inimigo (E), Coletáveis (C) e Decorações (arvores e cogumelos).
- Garantir que o personagem possa coletar todos os itens e liberar a saída (flood fill).
- **Bônus:**
    - Contador de movimentos (passos) aparece na tela.
    - Implementação da instância Z para aspecto de profundidade dos objetos.
    - Animação de sprite: o personagem e o inimigo são atualizados com frames sequenciais para simular o movimento.
    - Inimigo com perseguição: segue o jogador ininterruptamente pelo mapa.
    - Animações de fim de jogo: vitória ou derrota com efeitos visuais.
    - Display: cogumelos (nas paredes) e árvores (no chão) aparecem de forma aleatório dependendo do tamanho do mapa.

## Instalação

Este projeto depende da biblioteca gráfica **MLX42**, que requer as seguintes dependências:

### No Linux (Debian / Ubuntu)

1. Instale os pacotes necessários:
    ```bash
    sudo apt update
    sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev cmake

2. Clone o projeto e compile MLX42:
   ```bash
    git clone https://github.com/robertodelfranco/42-so_long.git
    cd MLX42
    cmake -B build
    cmake --build build
    sudo cmake --install build

## Uso

- Controles:
    - W move para cima
    - S move para baixo
    - A move para a esquerda
    - D move para a direita
    - ESC fecha a janela do jogo

Para rodar o jogo:
  ```bash
    make bonus
    ./so_long_bonus maps/bonus_maps/mov_small.ber
