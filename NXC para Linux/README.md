Para entender para que esses arquivos servem, dê uma olhada no link:

[NXC para Linux](https://github.com/UnbDroid/SEK/wiki/NXC-para-Linux)

Os arquivos desta pasta são:

* ```teste.nxc``` é um arquivo que simplesmente contém um ```HelloWorld``` para testar se o arquivo compilou.
* ```config.py``` é um arquivo que quando executado, instala o necessário. Caso não dê certo, leia o ```nxtlinux.txt```. Não usaremos essa abordagem porque pode trazer mais problemas e portanto será explicado como instalar manualmente.
* ```C.sublime-build``` é um arquivo que faz automaticamente a compilação de um arquivo ```.c```
* ```Default (Linux).sublime-keymap``` é um arquivo de configuração para ao apertar ```Alt```+```Shift```+```F```, fazer a identação de um código(de acordo com algumas regras). Não utilizaremos nesse tutorial.
* ```nxc.sublime-build``` é um arquivo responsável para compilar o NXC e enviar diretamente para o cérebro conectado.
* ```nxc.sublime-syntax``` é um arquivo para a linguagem NXC, que não é padrão do sublime e portanto temos que dizer as regras relacionadas, tais como cores de palavras fixas, cores de funções entre outras coisas. É importante dizer que é facilmente editavel e ainda não está completo para uma boa leitura de um código.
* ```45-legonxt.rules``` é um arquivo de configuração utilizado na instalação.
* ```nxtlinux.txt``` é um arquivo retirado da internet(através deste [link](http://bricxcc.sourceforge.net/nbc/doc/nxtlinux.txt)) que é um guia o qual foi inspirado para fazer este.