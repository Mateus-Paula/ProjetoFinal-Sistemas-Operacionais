
# ProjetoFinal-Sistemas-Operacionais
O trecho de código tem como objetivo zerar o saldo de uma conta (from) através de várias transferências para a outra (to). Contudo, acontece uma falha em sua execução causada por um dos problemas relativos à concorrência apresentados em sala. Para que o código seja executado com sucesso, é necessário identificar o problema e apresentar uma solução, com base nas observações relativas aos problemas.

## Como executar
Em ambas as plataformas, tanto no linux quanto no windows, fez-se necessário a instalação do gcc diretamente nos terminais. E para simular o SO (sistema operacional) linux/Ubuntu foi utilizado o Oracle Virtual Box, o qual cria a simulação de outros sistemas operacionais

### No linux:
Foi utilizado o editor de texto gedit, no arquivo de imagem do teste no linux os seguinte comandos aparecem: 

  1. Entrar no Terminal Linux
  2. mkdir projeto = Criar a pasta (projeto) dentro de Home/"User"
  3. Baixar o arquivo proj3.c, que contém o código fonte do trabalho, na pasta recém criada (projeto)
  3. cd projeto =                                         entra no diretório projeto
  4. gcc -o "nome do arquivo compilado desejado" proj3.c -lpthread =                   compilação do arquivo proj3.c utilizando o gcc
  5. ./projeto =                                          execução do arquivo
  
### No windows:
Passos:

  1. Criar a pasta (projeto)  para inserir o arquivo proj3.c
  2. Baixar o arquivo proj3.c, que contém o código fonte do trabalho, na pasta recém criada (projeto)
  3. Baixar o programa mingw-get-setup no site: https://osdn.net/projects/mingw/releases/ e instalar no Windows na pasta default C:\MinGW
  4. Na tela MinGW Installation Manager, marcar os pacotes "mingw32-base" e mingw32-gcc-objc", clicar na opção Installation, Apply Changes e, por último, em apply
  5. Ainda na Tela MinGW Installation Manager, entrar em "All Packages", marcar os três pacotes "mingw32-threads-w32" (bibliotecas do POSIX) e instalar
  6. Adicionar a pasta "C:\MinGW\bin" na variável de ambiente PATH
  7. Executar o cmd (Prompt de Comando) do Windows
  8. Entrar na pasta Projeto criada no item 1
  9. Compilar o arquivo proj3.c da seguinte forma: gcc -o "nome do arquivo compilado desejado" proj3.c -lpthread
  10. Executar o programa digitando: projeto
    
  
  
  

## Resultado
Os resultados nos sistemas operacionais são diferentes, entretanto a "bagunça" entre as impressões geradas pelo programa é similar em ambos SO's, isso é, a concorrência de processos e threads se faz presente nesse momento, uma vez que eles competem por um lugar de processamento sem que, necessariamente, sigam uma ordem de execução.

Percebe-se também, que o objetivo de zerar uma conta (c1) com a transferência para uma outra conta (c2) foi alcançada e, além disso, a conta to (c1), responsável por "mandar" o dinheiro para a conta from (c2), também recebe dinheiro em um depósito toda vez que um contador atinge 10 contagens.

No final de tudo, todos os requisitos foram atendidos, são eles:
  1. A conta to pode receber mais de uma transferência simultânea;
  2. A conta from pode enviar mais de uma transferência simultânea;
  3. A conta from não pode enviar dinheiro se não tiver mais saldo;
  4. A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode
  receber e a conta que recebia pode enviar;
  5. Poderão ser realizadas até 100 transações simultâneas de transferência.
