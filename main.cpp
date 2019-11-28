/*Arthur Procópio (34464), Fabrício Goncalves do Carmo (35007), Guilherme de Jesus (35070). P4
O programa a seguir é uma compilação de 3 jogos relacionados a palavras em que, um deles é a clássica forca, que fez parte da infancia
de muita gente, o segundo jogo é um jogo em que da o tamanho da palavra e o usuario entre com, 4 consoantes e uma vogal, respectivamente
e logo apos a palavra é exibida com as letras que o usuario deu, e este tera de adivinha-la, e o terceiro é um embaralhamento da palavra
sorteada e usuario tera de adivinhar a palavra usada*/
#include <iostream>
#include "palavras.h"
#include <mmsystem.h>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void Menu();//Imprime e executa o menu
void dormir( clock_t wait );//Recebe valores inteiros em milesegundos e "pausa" a execução do programa neste tempo
void Loading();//Imprime um "Loading" (tela de carregamento)
void intro();//Imprime a classica intro do console: Playstation 1
void Jogodaforca();//Imprime e executa o jogo da forca
void JogoDoSilvioSantos();//Imprime e executa o jogo das "4 consoantes e uma vogal"
void JogoEmbaralhaPalavras ();//Imprime e executa o jogo de embaralhar as letras de uma palavra
int main()
{
    intro();
    Menu();
    return 0;
}
void dormir( clock_t wait )
{
    clock_t goal = ( wait + clock() );
    while( goal > clock() );
}
void Loading()
{
    for (int i=0; i<3; i++)
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n                                L O A D I N G.";
        dormir(500);
        system("cls");
        cout<<"\n\n\n\n\n\n\n                                L O A D I N G .";
        dormir(500);
        system("cls");
        cout<<"\n\n\n\n\n\n\n                                L O A D I N G  .";
        dormir(500);
        system("cls");
        cout<<"\n\n\n\n\n\n\n                                L O A D I N G    .";
        dormir(800);
    }
}
void intro()
{

    cout<<" P A R A  U M A  M E L H O R  E X P E R I E N C I A  M A X I M I Z E  A  T E L A";
    dormir(4000);
    system("cls");
    cout<<"                                  S O N Y\n"
        <<"                                    ..\n"
        <<"                                   .=+=;\n"
        <<"                                  :=+++=.\n"
        <<"                                :=++===++=.\n"
        <<"                              :++++==++++++=.\n"
        <<"                            :++++++++++++++++=.\n"
        <<"                          :++++++#*+++==++++++*=.\n"
        <<"                        :+*++++###++++==++++++++*+.\n"
        <<"                      :+*++++#####++++==+++++++++**+.\n"
        <<"                    :***+*++######+++++=++++++++++***+.\n"
        <<"                  :******+++++####+++++=++++++++++*****+.\n"
        <<"                :********+++++++##++++==++++++++++*******+.\n"
        <<"              :**********+++++++++++++=+++++++++++**********.\n"
        <<"            =##***********+++++++++=++==++++++++++**********#*:\n"
        <<"            .*#**********++++++++++=+++=++++++++++**********##.\n"
        <<"              .+*********++++++++++=+++++#+++++++**********+\n"
        <<"                .+*******++++++++++==++++###++++++*******+\n"
        <<"                  .+*****++++++++++==++++#####++++*****=\n"
        <<"                    .+***++++++++++=+++++######++****=\n"
        <<"                      .+**+++++++++=+++++####++++**=\n"
        <<"                        .=*++++++++=+++++##+++++*=\n"
        <<"                          .=+++++++=+++++++++++=\n"
        <<"                            .=+++++=++++=++++=\n"
        <<"                              .=+++==+==+++:\n"
        <<"                                .=++===++:\n"
        <<"                                  .=+==: \n"
        <<"                                    .. \n"
        <<"                             C O M P U T E R\n"
        <<"                         E N T E R T A I N M E N T";
    PlaySound("psonePT1.wav", NULL, SND_FILENAME);
    system("cls");
    cout<<"\n                         :#*+=:.'\n"
        <<"                         :#########+=:.\n"
        <<"                         :###############+=.\n"
        <<"                         :##########**#######+.\n"
        <<"                         :#########+   *#######*.\n"
        <<"                         :#########=   =#########.\n"
        <<"                         :#########=   =##########\n"
        <<"                         :#########=   =##########.\n"
        <<"                         :#########=   =##########:\n"
        <<"                         :#########=   =##########:\n"
        <<"                         :#########=   =##########\n"
        <<"                         :#########=   =#########:\n"
        <<"                         =#########=   =#######*.\n"
        <<"                   .:=****#########=      ...\n"
        <<"             .:=+**********########=   ..:===++++++++==:..\n"
        <<"        :=+************+==#########++***********************+:\n"
        <<"    .=++=++++****+=:.    .########**********+=:.      :*******#:\n"
        <<"   +++++++===:.       .:=*########****+=:.       .:+**********+.\n"
        <<"   .=+++++++:....::=+++++**########=       .:=+************=:\n"
        <<"      .::==+++++++++++++=+#########= .:=+************+=:.\n"
        <<"                ....     :#########*+**********+=:.\n"
        <<"                         .=+*######*=======:.\n"
        <<"                               .:+**=:.\n\n"
        <<"                      P l a y S t a t i o n\n"
        <<"                           Licensed by\n"
        <<"         S O N Y  C O M P U T E R  E N T E R T A I N M E N T";
    PlaySound("psonoPT2.wav", NULL, SND_NOWAIT);
    system("cls");
}
void Menu()
{
    int CaseMenu;
    system("color 02");
    system("cls");
    cout<<"Para jogar:-SUPER-FORCA-BROS--------------Digite 1!!\n"
        <<"Para jogar:-RODA-A-RODA-JEQUITI-----------Digite 2!!\n"
        <<"Para jogar:-EMBARALHA-PALAVRAS------------Digite 3!!\n"
        <<"Para sair:--------------------------------Digite 0!!\n";
    cin>>CaseMenu;
    system("cls");
    if (CaseMenu==1||CaseMenu==2||CaseMenu==3||CaseMenu==0)
        switch (CaseMenu)
        {
        case 1:
            Jogodaforca();
            break;
        case 2:
            JogoDoSilvioSantos();
            break;
        case 3:
            JogoEmbaralhaPalavras();
            break;
        case 0:
            PlaySound("sm64_mario_thank_you.wav", NULL, SND_FILENAME);
        }
    else
        Menu();
}

void Jogodaforca()
{
    char categoria[MAX_CHARS], palavra[MAX_CHARS], Letra[MAX_CHARS+6], LetrasAcertadas[MAX_CHARS];
    int Tamanho, Erros=0, ContAcertos=0, Tentativas=0;
    system("color 02");
    Loading();
    system("cls");
    cout<<"\n\n\n\n\n\n\n                                  S U P E R \n"
        <<"                                 F O R C A 64";
    PlaySound("sm64_mario_its_me.wav", NULL, SND_FILENAME);
    dormir(800);
    system("cls");
    sorteiaCategoria(categoria);
    sorteiaPalavra(categoria, palavra);
    Tamanho=strlen(palavra);
    for (int i=0; i<Tamanho; i++)
        LetrasAcertadas[i]='-';
    LetrasAcertadas[Tamanho]=0;
    do
    {
        system("cls");
        switch (Erros)
        {
        case 1:
            cout<<" :@%@%###########################################@.\n"
                <<" :%#####%#%%%####%%###%%%%%%%%%%%%#####%%%%%%%%@%@.\n"
                <<" :%####@   .=%%%%%%#=:            .@*#%\n"
                <<" :%#*##%  :*%%%%%*.               .@+*#\n"
                <<" :%####%:#%%%%%+                  .@+*#\n"
                <<" :%#%##%%%%%%=                    .@+*# Categotia: "<<categoria<<endl
                <<" :%#####%%#:                      .@+*# Tentativas restantes: "<<(Erros-6)*-1<<endl
                <<" :%#%%#%*                         :@+*%\n"
                <<" :%####%                          .@+*#\n"
                <<" :%####%                          .@+*%+#%=\n"
                <<" :%####%                          :@+*##*:\n"
                <<" :%####%                          ****##\n"
                <<" :@####%\n"
                <<" :%####%                          .#:#=#:#.\n"
                <<" :%####%                       .*#*::==:=###.\n"
                <<" :@####%                      =#***=+::*+###%=\n"
                <<" :@####%                     :#*##%%#%%#%%%%#%:      "<<LetrasAcertadas<<endl
                <<" :@####%                     :#%#%##*++*###*%%:\n"
                <<" :@####%                     .=%.  ++ .+*.:=@*:\n"
                <<" :@####%                     .:%:: =. .:+ =+%**\n"
                <<" :@####%                      ..:@@=.:::*@@+==\n"
                <<" :@####%                       ..+*#*#%#*#=:\n"
                <<" :@####%                       :+*+::=+*#*:\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<"Entre com uma letra:";
            break;
        case 2:
            cout<<" :@%@%###########################################@.\n"
                <<" :%#####%#%%%####%%###%%%%%%%%%%%%#####%%%%%%%%@%@.\n"
                <<" :%####@   .=%%%%%%#=:            .@*#%\n"
                <<" :%#*##%  :*%%%%%*.               .@+*#\n"
                <<" :%####%:#%%%%%+                  .@+*#\n"
                <<" :%#%##%%%%%%=                    .@+*# Categotia: "<<categoria<<endl
                <<" :%#####%%#:                      .@+*# Tentativas restantes: "<<(Erros-6)*-1<<endl
                <<" :%#%%#%*                         :@+*%\n"
                <<" :%####%                          .@+*#\n"
                <<" :%####%                          .@+*%+#%=\n"
                <<" :%####%                          :@+*##*:\n"
                <<" :%####%                          ****##\n"
                <<" :@####%\n"
                <<" :%####%                          .#:#=#:#.\n"
                <<" :%####%                       .*#*::==:=###.\n"
                <<" :@####%                      =#***=+::*+###%=\n"
                <<" :@####%                     :#*##%%#%%#%%%%#%:      "<<LetrasAcertadas<<endl
                <<" :@####%                     :#%#%##*++*###*%%:\n"
                <<" :@####%                     .=%.  ++ .+*.:=@*:\n"
                <<" :@####%                     .:%:: =. .:+ =+%**\n"
                <<" :@####%                      ..:@@=.:::*@@+==\n"
                <<" :@####%                       ..+*#*#%#*#=:\n"
                <<" :@####%                       :+*+::=+*#*:\n"
                <<" :@####%                    .+##\n"
                <<" :@####%                   +**#\n"
                <<" :@####%                  =#*#%\n"
                <<" :@####%                 ..:+%*\n"
                <<" :@####%                   .=+\n"
                <<" :@####%                  :..:\n"
                <<" :@####%               :::=:=\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<"Entre com uma letra:";
            break;
        case 3:
            cout<<" :@%@%###########################################@.\n"
                <<" :%#####%#%%%####%%###%%%%%%%%%%%%#####%%%%%%%%@%@.\n"
                <<" :%####@   .=%%%%%%#=:            .@*#%\n"
                <<" :%#*##%  :*%%%%%*.               .@+*#\n"
                <<" :%####%:#%%%%%+                  .@+*#\n"
                <<" :%#%##%%%%%%=                    .@+*# Categotia: "<<categoria<<endl
                <<" :%#####%%#:                      .@+*# Tentativas restantes: "<<(Erros-6)*-1<<endl
                <<" :%#%%#%*                         :@+*%\n"
                <<" :%####%                          .@+*#\n"
                <<" :%####%                          .@+*%+#%=\n"
                <<" :%####%                          :@+*##*:\n"
                <<" :%####%                          ****##\n"
                <<" :@####%\n"
                <<" :%####%                          .#:#=#:#.\n"
                <<" :%####%                       .*#*::==:=###.\n"
                <<" :@####%                      =#***=+::*+###%=\n"
                <<" :@####%                     :#*##%%#%%#%%%%#%:      "<<LetrasAcertadas<<endl
                <<" :@####%                     :#%#%##*++*###*%%:\n"
                <<" :@####%                     .=%.  ++ .+*.:=@*:\n"
                <<" :@####%                     .:%:: =. .:+ =+%**\n"
                <<" :@####%                      ..:@@=.:::*@@+==\n"
                <<" :@####%                       ..+*#*#%#*#=:\n"
                <<" :@####%                       :+*+::=+*#*:\n"
                <<" :@####%                    .+##           %*\n"
                <<" :@####%                   +**#             ##*\n"
                <<" :@####%                  =#*#%             %*##+\n"
                <<" :@####%                 ..:+%*             *%=::=:\n"
                <<" :@####%                   .=+               :.  .:.\n"
                <<" :@####%                  :..:               . .  :=:\n"
                <<" :@####%               :::=:=                 :+::+*:\n"
                <<" :@####%                   .                   .\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<"Entre com uma letra:";
            break;
        case 4:
            cout<<" :@%@%###########################################@.\n"
                <<" :%#####%#%%%####%%###%%%%%%%%%%%%#####%%%%%%%%@%@.\n"
                <<" :%####@   .=%%%%%%#=:            .@*#%\n"
                <<" :%#*##%  :*%%%%%*.               .@+*#\n"
                <<" :%####%:#%%%%%+                  .@+*#\n"
                <<" :%#%##%%%%%%=                    .@+*# Categotia: "<<categoria<<endl
                <<" :%#####%%#:                      .@+*# Tentativas restantes: "<<(Erros-6)*-1<<endl
                <<" :%#%%#%*                         :@+*%\n"
                <<" :%####%                          .@+*#\n"
                <<" :%####%                          .@+*%+#%=\n"
                <<" :%####%                          :@+*##*:\n"
                <<" :%####%                          ****##\n"
                <<" :@####%\n"
                <<" :%####%                          .#:#=#:#.\n"
                <<" :%####%                       .*#*::==:=###.\n"
                <<" :@####%                      =#***=+::*+###%=\n"
                <<" :@####%                     :#*##%%#%%#%%%%#%:      "<<LetrasAcertadas<<endl
                <<" :@####%                     :#%#%##*++*###*%%:\n"
                <<" :@####%                     .=%.  ++ .+*.:=@*:\n"
                <<" :@####%                     .:%:: =. .:+ =+%**\n"
                <<" :@####%                      ..:@@=.:::*@@+=\n"
                <<" :@####%                       ..+*#*#%#*#=:\n"
                <<" :@####%                       :+*+::=+*#*:\n"
                <<" :@####%                     .+##*+#*######%%*.\n"
                <<" :@####%                    +**#*=+*+****==#%##*\n"
                <<" :@####%                  =#*#%**********####%*##+\n"
                <<" :@####%                 ..:+%***********###%*%=::=:\n"
                <<" :@####%                   .=+ #******#####%% :.  .:.\n"
                <<" :@####%                  :..: #########%%%%# . .  :=:\n"
                <<" :@####%               :::=:=  #**##%%%%%###%  :+::+*:\n"
                <<" :@####%                   .  :***##%..%***##=  .\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<"Entre com uma letra:";
            break;
        case 5:
            cout<<" :@%@%###########################################@.\n"
                <<" :%#####%#%%%####%%###%%%%%%%%%%%%#####%%%%%%%%@%@.\n"
                <<" :%####@   .=%%%%%%#=:            .@*#%\n"
                <<" :%#*##%  :*%%%%%*.               .@+*#\n"
                <<" :%####%:#%%%%%+                  .@+*#\n"
                <<" :%#%##%%%%%%=                    .@+*# Categotia: "<<categoria<<endl
                <<" :%#####%%#:                      .@+*# Tentativas restantes: "<<(Erros-6)*-1<<endl
                <<" :%#%%#%*                         :@+*%\n"
                <<" :%####%                          .@+*#\n"
                <<" :%####%                          .@+*%+#%=\n"
                <<" :%####%                          :@+*##*:\n"
                <<" :%####%                          ****##\n"
                <<" :@####%\n"
                <<" :%####%                          .#:#=#:#.\n"
                <<" :%####%                       .*#*::==:=###.\n"
                <<" :@####%                      =#***=+::*+###%=\n"
                <<" :@####%                     :#*##%%#%%#%%%%#%:      "<<LetrasAcertadas<<endl
                <<" :@####%                     :#%#%##*++*###*%%:\n"
                <<" :@####%                     .=%.  ++ .+*.:=@*:\n"
                <<" :@####%                     .:%:: =. .:+ =+%**\n"
                <<" :@####%                      ..:@@=.:::*@@+=\n"
                <<" :@####%                       ..+*#*#%#*#=:\n"
                <<" :@####%                       :+*+::=+*#*:\n"
                <<" :@####%                     .+##*+#*######%%*.\n"
                <<" :@####%                    +**#*=+*+****==#%##*\n"
                <<" :@####%                  =#*#%**********####%*##+\n"
                <<" :@####%                 ..:+%***********###%*%=::=:\n"
                <<" :@####%                   .=+ #******#####%% :.  .:.\n"
                <<" :@####%                  :..: #########%%%%# . .  :=:\n"
                <<" :@####%               :::=:=  #**##%%%%%###%  :+::+*:\n"
                <<" :@####%                   .  :***##%..%***##=  .\n"
                <<" :@####%                      ****#%#\n"
                <<" :@####%                     .#**##%=\n"
                <<" :@####%                     +***##%\n"
                <<" :@####%                   :=+***##%\n"
                <<" :@####%                  ++==*#%%%@\n"
                <<" :@####%                  .*###%#+=.\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<"Entre com uma letra:";
            break;
        case 0:
            cout<<" :@%@%###########################################@.\n"
                <<" :%#####%#%%%####%%###%%%%%%%%%%%%#####%%%%%%%%@%@.\n"
                <<" :%####@   .=%%%%%%#=:            .@*#%\n"
                <<" :%#*##%  :*%%%%%*.               .@+*#\n"
                <<" :%####%:#%%%%%+                  .@+*#\n"
                <<" :%#%##%%%%%%=                    .@+*# Categotia: "<<categoria<<endl
                <<" :%#####%%#:                      .@+*# Tentativas restantes: 6\n"
                <<" :%#%%#%*                         :@+*%\n"
                <<" :%####%                          .@+*#\n"
                <<" :%####%                          .@+*%+#%=\n"
                <<" :%####%                          :@+*##*:\n"
                <<" :%####%                          ****##\n"
                <<" :@####%                          *#**#%\n"
                <<" :%####%                         .##*%*#\n"
                <<" :%####%                        =%*%+ ###+\n"
                <<" :@####%                        @*#    #*%:\n"
                <<" :@####%                        @+#    =##+          "<<LetrasAcertadas<<endl
                <<" :@####%                        =%*%+==%*%\n"
                <<" :@####%                          +##%##*\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<"Entre com uma letra:";
            break;
        }
        cin>>Letra[Tentativas];
        Tentativas++;
        for (int i=0; i<Tentativas; i++)
            for (int j=0; j<i; j++)
        while (Letra[i]<'a'||Letra[i]>'z'||Letra[i]==Letra[j])
        {
            cout<<"Caracter invalido, entre com nova letra: ";
            cin>>Letra[i];
        }
        for (int i=0; i<Tamanho; i++)
        {
            if (Letra[Tentativas-1]==palavra[i])
            {
                LetrasAcertadas[i]=Letra[Tentativas-1];
                ContAcertos++;

            }
        }
        if (ContAcertos==0)
        {
            Erros++;
            PlaySound("sm64_boo.wav", NULL, SND_FILENAME);
        }
        else
            PlaySound("sm64_mario_yahoo.wav", NULL, SND_FILENAME);
        ContAcertos=0;

    }
    while (strcmp(palavra, LetrasAcertadas)&&Erros<6);
    if (Erros<6)
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n                                        V O C E\n"
            <<"                                       V E N C E U!!!";
        PlaySound("sm64_here_we_go.wav", NULL, SND_FILENAME);
    }
    else
    {

        system("cls");

        cout    <<" :@%@%###########################################@.\n"
                <<" :%#####%#%%%####%%###%%%%%%%%%%%%#####%%%%%%%%@%@.\n"
                <<" :%####@   .=%%%%%%#=:            .@*#%\n"
                <<" :%#*##%  :*%%%%%*.               .@+*#\n"
                <<" :%####%:#%%%%%+                  .@+*#\n"
                <<" :%#%##%%%%%%=                    .@+*# Categotia: "<<categoria<<endl
                <<" :%#####%%#:                      .@+*# Tentativas restantes: 0\n"
                <<" :%#%%#%*                         :@+*%\n"
                <<" :%####%                          .@+*#\n"
                <<" :%####%                          .@+*%+#%=\n"
                <<" :%####%                          :@+*##*:\n"
                <<" :%####%                          ****##\n"
                <<" :@####%\n"
                <<" :%####%                          .#:#=#:#.\n"
                <<" :%####%                       .*#*::==:=###.\n"
                <<" :@####%                      =#***=+::*+###%=\n"
                <<" :@####%                     :#*##%%#%%#%%%%#%:      "<<LetrasAcertadas<<endl
                <<" :@####%                     :#%#%##*++*###*%%:\n"
                <<" :@####%                     .=%.  ++ .+*.:=@*:\n"
                <<" :@####%                     .:%:: =. .:+ =+%**\n"
                <<" :@####%                      ..:@@=.:::*@@+=\n"
                <<" :@####%                       ..+*#*#%#*=:\n"
                <<" :@####%                        :+*+::=+*#*:\n"
                <<" :@####%                     .+##*+#*######%%*.\n"
                <<" :@####%                    +**#*=+*+****==#%##*\n"
                <<" :@####%                  =#*#%**********####%*##+\n"
                <<" :@####%                 ..:+%***********###%*%=::=:\n"
                <<" :@####%                   .=+ #******#####%% :.  .:.\n"
                <<" :@####%                  :..: #########%%%%# . .  :=:\n"
                <<" :@####%               :::=:=  #**##%%%%%###%  :+::+*:\n"
                <<" :@####%                   .  :***##%..%***##=  .\n"
                <<" :@####%                      ****#%#  ##**###\n"
                <<" :@####%                     .#**##%=  =#**##%.\n"
                <<" :@####%                     +***##%    #****#*\n"
                <<" :@####%                   :=+***##%    ##*++++*+\n"
                <<" :@####%                  ++==*#%%%@    %#*+==+*%#\n"
                <<" :@####%                  .*###%#+=.    .==**####.\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n"
                <<" :@####%\n";
        dormir(1000);
        system("cls");
        cout<<"\n\n\n\n\n\n\n                                   G A M E  O V E R";
        PlaySound("sm64_bowser_message.wav", NULL, SND_FILENAME);
        dormir(400);
    }
    Menu();
}
void JogoDoSilvioSantos()
{

    char categoria[MAX_CHARS], palavra[MAX_CHARS], Consoante[4], VetorPalavra[MAX_CHARS], Vogal, Resposta[MAX_CHARS];
    int Tamanho;
    system("color 02");
    Loading();
    system("cls");
    sorteiaCategoria(categoria);
    sorteiaPalavra(categoria, palavra);
    Tamanho=strlen(palavra);
    cout<<"\n\n\n\n\n\n\n                                  R O D A"
        <<"\n                                A  \n                                  R O D A"
        <<"\n                              J E Q U I T I";
    PlaySound("Roda a Roda Jequiti.wav", NULL, SND_FILENAME);
    system("cls");
    for (int i=0; i<Tamanho; i++)
        VetorPalavra[i]='-';
    VetorPalavra[Tamanho]=0;
    cout<<categoria<<"      "
        <<VetorPalavra
        <<"\nEntre com 4 consoantes: ";
    for (int i=0; i<4; i++)
    {
        cin>>Consoante[i];
        while (Consoante[i]=='a'||Consoante[i]=='e'||Consoante[i]=='i'||Consoante[i]=='o'||Consoante[i]=='u'||Consoante[i]<'a'||Consoante[i]>'z')
        {
            cout<<"Nao eh uma consoante, entre com uma consoante: ";
            cin>>Consoante[i];
        }
    }
    cout<<"\nEntre com uma vogal: ";
    cin>>Vogal;
    while (Vogal!='a'&&Vogal!='e'&&Vogal!='i'&&Vogal!='o'&&Vogal!='u')
    {
        cout<<"Nao eh uma vogal, entre com uma vogal: ";
        cin>>Vogal;
    }
    for (int i=0; i<Tamanho; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (palavra[i]==Consoante[j])
                VetorPalavra[i]=Consoante[j];

                if(palavra[i]==Vogal)
                    VetorPalavra[i]=Vogal;

        }
    }
    system("cls");
    cout<<"A palavra agora esta assim: "<<VetorPalavra;
    cout<<"\nA palavra eh? ";
    cin>>Resposta;
    if (strcmp(Resposta, palavra)==0)
    {
        cout<<"Parabens";
        dormir(1000);
    }
    else
    {
        cout<<"tente na proxima";
        dormir(1000);
    }
    Menu();
}
void JogoEmbaralhaPalavras()
{
    char categoria[MAX_CHARS], palavra[MAX_CHARS], VetorPalavra[MAX_CHARS], Resposta[MAX_CHARS], aux;
    int Tamanho;
    system("color 02");
    sorteiaCategoria(categoria);
    sorteiaPalavra(categoria, palavra);
    strcpy(VetorPalavra, palavra);
    Tamanho=strlen(palavra);
    Loading();
    system("cls");
    for (int i=0; i<Tamanho; i++)
    {
        for (int j=0; j<Tamanho; j++)
        {
            aux=VetorPalavra[i];
            VetorPalavra[i]=VetorPalavra[j];
            VetorPalavra[j]=aux;
        }
    }
    cout<<VetorPalavra
        <<"\nDica: "<<categoria<<endl
        <<"e a palavra eh? ";
    cin>>Resposta;
    for (int i=0; Resposta[i]=='\0'; i++)
        while (Resposta[i]<'a'||Resposta[i]>'z')
        {
            cout<<"\nA reposta contem caracteres invalidos, entre com uma nova resposta: ";
            cin>>Resposta;
        }
    if (strcmp(Resposta, palavra)==0)
        cout<<"\nParabens, voce venceu!!!";
    else
        cout<<"\nTente na proxima";
    dormir(3000);
    Menu();
}
