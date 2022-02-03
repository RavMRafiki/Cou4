#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace sf;


int main()
{
    srand(time(0));     

    RenderWindow window(VideoMode(1280,720), "Cou");

    //wczytywanie tekstur
    Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11;
    t1.loadFromFile("images/cou.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/ikonycou.png");
    t4.loadFromFile("images/tophud.png");
    t5.loadFromFile("images/coin.png");
    t6.loadFromFile("images/backgroundSpanko.png");
    t7.loadFromFile("images/sheep.png");
    t8.loadFromFile("images/backgroundPicie.png");
    t9.loadFromFile("images/waterbucket.png");
    t10.loadFromFile("images/backgroundJedzenie.png");
    t11.loadFromFile("images/apple.png");


    //zarządanie tymi teksturami
    Sprite cou(t1), background(t2), ikony(t3), ikonamleko(t3), ikonaspanko(t3), ikonajedzenie(t3), ikonapicie(t3), tophud(t4),coin(t5),backgroundSpanko(t6),sheep(t7),backgroundPicie(t8),waterbucket(t9),coujedzenie(t1),backgroundJedzenie(t10),apple(t11);
    cou.setScale(sf::Vector2f(0.35f, 0.35f));
    cou.setPosition(sf::Vector2f(380.f, 120.f));
    ikonamleko.setTextureRect(IntRect(0, 0, 100, 100));
    ikonamleko.setPosition(sf::Vector2f(425.f, 20.f));
    ikonajedzenie.setTextureRect(IntRect(101, 0, 99, 100));
    ikonajedzenie.setPosition(sf::Vector2f(545.f, 20.f));
    ikonaspanko.setTextureRect(IntRect(201, 0, 99, 100));
    ikonaspanko.setPosition(sf::Vector2f(665.f, 20.f));
    ikonapicie.setTextureRect(IntRect(301, 0, 99, 100));
    ikonapicie.setPosition(sf::Vector2f(785.f, 20.f));
    coin.setPosition(sf::Vector2f(1160.f, 20.f));
    coin.setScale(sf::Vector2f(1.1f, 1.1f));
    backgroundSpanko.setPosition(sf::Vector2f(0.f, 140.f));
    backgroundSpanko.setScale(sf::Vector2f(0.67f, 0.67f));
    backgroundPicie.setPosition(sf::Vector2f(0.f, 140.f));
    coujedzenie.setScale(sf::Vector2f(0.05f, 0.05f));
    coujedzenie.setPosition(sf::Vector2f(640.f, 360.f));
    backgroundJedzenie.setPosition(sf::Vector2f(0.f, 140.f));
    backgroundJedzenie.setScale(sf::Vector2f(5.f, 5.f));
    apple.setScale(sf::Vector2f(0.05f, 0.05f));
    apple.setPosition(sf::Vector2f(700.f, 400.f));
    //zmienne
    int dx=0,dy=0; bool rotate=0; int colorNum=1;
    float timer = 0.f, delay = 0.3f;
    int money = 27;
    bool keyM{}, keyS{}, keyJ{}, keyP{}, keySpace{};
    int keyNumber{};
    bool graSpanko{};
    bool graPicie{};
    bool graJedzenie{};
    int tabSpankoX[9]{};
    int tabSpankoY[9]{};
    int spankoLiczbaCou{};
    float zape軟ienieMleka = 0.f;
    float zape軟ienieSpanka = 10.f;
    float zape軟ienieJedzenia = 10.f;
    float zape軟ieniePicia = 10.f;
    float wysokoBucketa = 0.f;
    int pozycjaCouX = 640, pozycjaCouY = 360, pozycjaAppleX=700,pozycjaAppleY=400;
    int level = 1;
    float mno積ik1 = 1, mno積ik2=1;
    
    //wczytanie zapisu gry
    std::string linijka;
    std::fstream plik;
    plik.open("save/save.txt", std::ios::in); 
    if (plik.good())
    {
        if (std::getline(plik, linijka)) {
            money = std::stoi(linijka);
        }
        if (std::getline(plik, linijka)) {
            level = std::stoi(linijka);
        }
        if (std::getline(plik, linijka)) {
            zape軟ienieMleka = std::stof(linijka);
        }
        if (std::getline(plik, linijka)) {
            zape軟ienieSpanka = std::stof(linijka);
        }
        if (std::getline(plik, linijka)) {
            zape軟ienieJedzenia = std::stof(linijka);
        }
        if (std::getline(plik, linijka)) {
            zape軟ieniePicia = std::stof(linijka);
        }
    }
    else std::cout << "Nie wczytano save'a" << std::endl;
    plik.close();

    if (level == 2) {
        mno積ik1 = 1.5f;
        mno積ik2 = 3.f;
        t1.loadFromFile("images/cou2.png");
    }
    else if (level == 3) {
        mno積ik1 = 2.1f;
        mno積ik2 = 9.f;
        t1.loadFromFile("images/cou3.png");
    }
    else if (level ==4) {
        mno積ik1 = 3.f;
        mno積ik2 = 81.f;
        t1.loadFromFile("images/cou4.png");
    }
    else if (level > 4) {
        mno積ik1 = mno積ik1 * pow(1.03f,level-4);
        t1.loadFromFile("images/cou4.png");
        if (mno積ik1 > 4.3) { mno積ik1 = 5; }
        mno積ik2 = 81.f;
    }
    
    //stworzenie wypełnienia zasobów prostokątami
    RectangleShape mlekot這, spankot這, jedzeniet這, piciet這;
    mlekot這.setSize(Vector2f(100.f, 100.f));
    mlekot這.setFillColor(Color{222, 222, 222});
    mlekot這.setPosition(sf::Vector2f(425.f, 20.f));
    spankot這.setSize(Vector2f(100.f, 100.f));
    spankot這.setFillColor(Color{ 255, 246, 224 });
    spankot這.setPosition(sf::Vector2f(665.f, 20.f));
    jedzeniet這.setSize(Vector2f(100.f, 100.f));
    jedzeniet這.setFillColor(Color{ 224, 255, 226 });
    jedzeniet這.setPosition(sf::Vector2f(545.f, 20.f));
    piciet這.setSize(Vector2f(100.f, 100.f));
    piciet這.setFillColor(Color{ 224, 233, 255 });
    piciet這.setPosition(sf::Vector2f(785.f, 20.f));
    

    //wczytanie czcionki
    Font foncik;
    foncik.loadFromFile("fonts/Storytime.ttf");

    Text text, poziom;
    text.setFont(foncik);
    text.setString(std::to_string(money));
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(100);
    text.setPosition(sf::Vector2f(1000.f, 6.f));

    poziom.setFont(foncik);
    poziom.setString(std::to_string(level));
    poziom.setFillColor(sf::Color::White);
    poziom.setStyle(sf::Text::Bold);
    poziom.setCharacterSize(200);
    poziom.setPosition(sf::Vector2f(1025.f, 520.f));
    
    //mechanizm liczenia czasu
    Clock clock;
    Clock mleko;
    Clock spanko;
    Clock picie;
    Clock jedzenie;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        Event e;
        while (window.pollEvent(e))
            //wczytywanie działań na klawiaturze
        {
            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Up) dy = -5;
                else if (e.key.code == Keyboard::Left) dx = -5;
                else if (e.key.code == Keyboard::Right) dx = 5;
                else if (e.key.code == Keyboard::Down) dy = 5;
                else if (e.key.code == Keyboard::S) keyS = 1;
                else if (e.key.code == Keyboard::M) keyM = 1;
                else if (e.key.code == Keyboard::J) keyJ = 1;
                else if (e.key.code == Keyboard::P) keyP = 1;
                else if (e.key.code == Keyboard::Space) keySpace = 1;
                //else if (e.key.code == Mouse::Left) keyM = 1;
                else if (e.key.code == Keyboard::Escape) window.close();
            }
        }
    
    if (e.key.code == Keyboard::Num1) keyNumber = 1;
    else if (e.key.code == Keyboard::Num2) keyNumber = 2;
    else if (e.key.code == Keyboard::Num3) keyNumber = 3;
    else if (e.key.code == Keyboard::Num4) keyNumber = 4;
    else if (e.key.code == Keyboard::Num5) keyNumber = 5;
    else if (e.key.code == Keyboard::Num6) keyNumber = 6;
    else if (e.key.code == Keyboard::Num7) keyNumber = 7;
    else if (e.key.code == Keyboard::Num8) keyNumber = 8;
    else if (e.key.code == Keyboard::Num9) keyNumber = 9;
    
    //obliczenia dotyczące czasu w grze i jego efektów
    zape軟ienieMleka = mleko.getElapsedTime().asSeconds() / 5;
    if (zape軟ienieMleka >= 1) { zape軟ienieMleka = 1; };
    mlekot這.setSize(Vector2f(100.f, zape軟ienieMleka*100));
    mlekot這.setPosition(sf::Vector2f(425.f, 20.f+ 100 - zape軟ienieMleka * 100));
    if (mleko.getElapsedTime().asSeconds() >= 5) { 
        if (keyM == 1 && zape軟ienieSpanka>0.7f && zape軟ienieJedzenia>0.7f && zape軟ieniePicia>0.7f) { 
        //std::cout << "Odebra貫� Mleko" << std::endl;
            money += 50*mno積ik2; mleko.restart(); zape軟ieniePicia = zape軟ieniePicia - 0.025f; } }

    zape軟ienieSpanka = zape軟ienieSpanka - (spanko.getElapsedTime().asSeconds())/(100*(1/mno積ik1));
    spanko.restart();
    if (zape軟ienieSpanka>= 1) { zape軟ienieSpanka = 1; };
    if (zape軟ienieSpanka <= 0) { zape軟ienieSpanka = 0; };
    spankot這.setSize(Vector2f(100.f,zape軟ienieSpanka*100));
    spankot這.setPosition(sf::Vector2f(665.f, 20.f + 100.f - zape軟ienieSpanka * 100));

    zape軟ienieJedzenia = zape軟ienieJedzenia - (jedzenie.getElapsedTime().asSeconds()) / (100 * (1 / mno積ik1));
    jedzenie.restart();
    if (zape軟ienieJedzenia >= 1) { zape軟ienieJedzenia = 1; };
    if (zape軟ienieJedzenia <= 0) { zape軟ienieJedzenia = 0; };
    jedzeniet這.setSize(Vector2f(100.f, zape軟ienieJedzenia * 100));
    jedzeniet這.setPosition(sf::Vector2f(545.f, 20.f + 100.f - zape軟ienieJedzenia * 100));

    zape軟ieniePicia = zape軟ieniePicia - (picie.getElapsedTime().asSeconds()) / (200 * (1 / mno積ik1));
    picie.restart();
    if (zape軟ieniePicia >= 1) { zape軟ieniePicia = 1; };
    if (zape軟ieniePicia <= 0) { zape軟ieniePicia = 0; };
    piciet這.setSize(Vector2f(100.f, zape軟ieniePicia * 100));
    piciet這.setPosition(sf::Vector2f(785.f, 20.f + 100.f - zape軟ieniePicia * 100));
    if (keySpace == 1) { wysokoBucketa = wysokoBucketa + 20; }
    keySpace = 0;
    wysokoBucketa = wysokoBucketa - clock.getElapsedTime().asMilliseconds()*15;
    clock.restart();
    if (wysokoBucketa < 0) { wysokoBucketa = 0; }


    if (keyS == 1){
        graSpanko = 1;
        std::mt19937 generator(std::time(nullptr));
        std::uniform_int_distribution<int> liczbaCou(1, 9);
        std::uniform_int_distribution<int> pozycjaX(0, 1200);
        std::uniform_int_distribution<int> pozycjaY(300,620);
        spankoLiczbaCou = liczbaCou(generator);
        for (int i{}; i < 9; i++) {
            tabSpankoX[i] = pozycjaX(generator);
            tabSpankoY[i] = pozycjaY(generator);
        }
    }
    //włączanie minigier
    if (keyP == 1) {
        graPicie = 1;
    }
    if (keyJ == 1) {
        graJedzenie = 1;
        std::mt19937 generator(std::time(nullptr));
        std::uniform_int_distribution<int> pozycjaX(0, 1200);
        //   std::mt19937 generator(std::time(nullptr));
        std::uniform_int_distribution<int> pozycjaY(300, 620);
        pozycjaCouX = pozycjaX(generator);
        pozycjaCouY = pozycjaY(generator);
        pozycjaAppleX = pozycjaX(generator);
        pozycjaAppleY = pozycjaY(generator);

    }

    keyM = 0;
    keyS = 0;
    keyJ = 0;
    keyP = 0;
    text.setString(std::to_string(money));
    poziom.setString(std::to_string(level));
    window.clear(Color::White);
    window.draw(background);
    window.draw(cou);

    if (graSpanko == 1) {
        window.draw(backgroundSpanko);
        for (int i{}; i < spankoLiczbaCou; i++) {
            sheep.setPosition(Vector2f(tabSpankoX[i], tabSpankoY[i]));
            window.draw(sheep);
        }
        if (keyNumber == spankoLiczbaCou) {
            graSpanko = 0;
            zape軟ienieSpanka = 100.f;
            keyNumber = 0;
        }
        else if (keyNumber != 0) {
            graSpanko = 0;
            keyNumber = 0;
        }
    }


    if (graPicie == 1) {
        window.draw(backgroundPicie);
        waterbucket.setPosition(927.f, 700.f - wysokoBucketa);
        window.draw(waterbucket);
        if (wysokoBucketa >= 450) {
            graPicie = 0;
            zape軟ieniePicia = 100.f;
            keySpace = 0;
            wysokoBucketa = 0;
        }
    }
    if (graJedzenie == 1) {
        pozycjaCouX = pozycjaCouX + dx;
        pozycjaCouY = pozycjaCouY + dy;
        if (pozycjaCouY < 140) {
            pozycjaCouY = 140;
        }
        if (pozycjaCouY > 640) {
            pozycjaCouY = 640;
        }
        if (pozycjaCouX < 0) {
            pozycjaCouX = 0;
        }
        if (pozycjaCouX > 1200) {
            pozycjaCouX = 1200;
        }
        coujedzenie.setPosition(pozycjaCouX, pozycjaCouY);
        apple.setPosition(pozycjaAppleX, pozycjaAppleY);
        window.draw(backgroundJedzenie);
        window.draw(coujedzenie);
        window.draw(apple);
        if (pozycjaCouX > pozycjaAppleX - 60 && pozycjaCouX < pozycjaAppleX + 60 && pozycjaCouY < pozycjaAppleY + 100 && pozycjaCouY > pozycjaAppleY - 100 ) {
            graJedzenie = 0;
            zape軟ienieJedzenia = 100.f;
        }
    }
    //system zdobywania poziomów 
    if (level == 1 && money >= 1000) {
        level = 2;
        money = money - 1000;
        mno積ik1 = 1.5f;
        mno積ik2 = 3.f;
        t1.loadFromFile("images/cou2.png");
    }
    else if (level == 2 && money >= 10000) {
        level = 3;
        money = money - 10000;
        mno積ik1 = 2.1f;
        mno積ik2 = 9.f;
        t1.loadFromFile("images/cou3.png");
    }
    else if (level == 3 && money >= 100000) {
        level = 4;
        money = money - 100000;
        mno積ik1 = 3.f;
        mno積ik2 = 81.f;
        t1.loadFromFile("images/cou4.png");
    }
    else if (level >= 4 && money >= 1000000) {
        level++;
        money = money - 1000000;
        mno積ik1 = mno積ik1*1.03f;
        if (mno積ik1 > 4.3) { mno積ik1 = 5; }
        mno積ik2 = mno積ik2;
    }
    if (money < 0) { money = 0; }

    keySpace = 0;
    dx = 0;
    dy = 0;
    //wyświetlanie elementów okna gry
    window.draw(tophud);
    window.draw(coin);
    window.draw(text);
    window.draw(poziom);
    window.draw(mlekot這);
    window.draw(spankot這);
    window.draw(jedzeniet這);
    window.draw(piciet這);
    window.draw(ikonamleko);
    window.draw(ikonajedzenie);
    window.draw(ikonaspanko);
    window.draw(ikonapicie);
    window.display();
    }
    //zapis stanu gry
    plik.open("save/save.txt", std::ios::out);
    if (plik.good())
    {
        plik << money << std::endl;
        plik << level << std::endl;
        plik << zape軟ienieMleka << std::endl;
        plik << zape軟ienieSpanka << std::endl;
        plik << zape軟ienieJedzenia << std::endl;
        plik << zape軟ieniePicia << std::endl;

    }
    else std::cout << "Nie wczytano save'a" << std::endl;
    plik.close();
    return 0;
}
