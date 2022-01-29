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

   /* SoundBuffer a1, a2;
    a1.loadFromFile(audio/Moo.wav)*/
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
    float zape³nienieMleka = 0.f;
    float zape³nienieSpanka = 10.f;
    float zape³nienieJedzenia = 10.f;
    float zape³nieniePicia = 10.f;
    float wysokoœæBucketa = 0.f;
    int pozycjaCouX = 640, pozycjaCouY = 360, pozycjaAppleX=700,pozycjaAppleY=400;
    int level = 1;
    float mno¿nik1 = 1, mno¿nik2=1;

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
            zape³nienieMleka = std::stof(linijka);
        }
        if (std::getline(plik, linijka)) {
            zape³nienieSpanka = std::stof(linijka);
        }
        if (std::getline(plik, linijka)) {
            zape³nienieJedzenia = std::stof(linijka);
        }
        if (std::getline(plik, linijka)) {
            zape³nieniePicia = std::stof(linijka);
        }
    }
    else std::cout << "Nie wczytano save'a" << std::endl;
    plik.close();

    if (level == 2) {
        mno¿nik1 = 1.5f;
        mno¿nik2 = 3.f;
        t1.loadFromFile("images/cou2.png");
    }
    else if (level == 3) {
        mno¿nik1 = 2.1f;
        mno¿nik2 = 9.f;
        t1.loadFromFile("images/cou3.png");
    }
    else if (level ==4) {
        mno¿nik1 = 3.f;
        mno¿nik2 = 81.f;
        t1.loadFromFile("images/cou4.png");
    }
    else if (level > 4) {
        mno¿nik1 = mno¿nik1 * pow(1.03f,level-4);
        t1.loadFromFile("images/cou4.png");
        if (mno¿nik1 > 4.3) { mno¿nik1 = 5; }
        mno¿nik2 = 81.f;
    }

    RectangleShape mlekot³o, spankot³o, jedzeniet³o, piciet³o;
    mlekot³o.setSize(Vector2f(100.f, 100.f));
    mlekot³o.setFillColor(Color{222, 222, 222});
    mlekot³o.setPosition(sf::Vector2f(425.f, 20.f));
    spankot³o.setSize(Vector2f(100.f, 100.f));
    spankot³o.setFillColor(Color{ 255, 246, 224 });
    spankot³o.setPosition(sf::Vector2f(665.f, 20.f));
    jedzeniet³o.setSize(Vector2f(100.f, 100.f));
    jedzeniet³o.setFillColor(Color{ 224, 255, 226 });
    jedzeniet³o.setPosition(sf::Vector2f(545.f, 20.f));
    piciet³o.setSize(Vector2f(100.f, 100.f));
    piciet³o.setFillColor(Color{ 224, 233, 255 });
    piciet³o.setPosition(sf::Vector2f(785.f, 20.f));
    


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

    /*if (Keyboard::isKeyPressed(Keyboard::Down)) delay=0.05f;
    if (e.key.code == Mouse::Left) keyM = 1; */
    if (e.key.code == Keyboard::Num1) keyNumber = 1;
    else if (e.key.code == Keyboard::Num2) keyNumber = 2;
    else if (e.key.code == Keyboard::Num3) keyNumber = 3;
    else if (e.key.code == Keyboard::Num4) keyNumber = 4;
    else if (e.key.code == Keyboard::Num5) keyNumber = 5;
    else if (e.key.code == Keyboard::Num6) keyNumber = 6;
    else if (e.key.code == Keyboard::Num7) keyNumber = 7;
    else if (e.key.code == Keyboard::Num8) keyNumber = 8;
    else if (e.key.code == Keyboard::Num9) keyNumber = 9;

    zape³nienieMleka = mleko.getElapsedTime().asSeconds() / 5;
    if (zape³nienieMleka >= 1) { zape³nienieMleka = 1; };
    mlekot³o.setSize(Vector2f(100.f, zape³nienieMleka*100));
    mlekot³o.setPosition(sf::Vector2f(425.f, 20.f+ 100 - zape³nienieMleka * 100));
    if (mleko.getElapsedTime().asSeconds() >= 5) { 
        if (keyM == 1 && zape³nienieSpanka>0.7f && zape³nienieJedzenia>0.7f && zape³nieniePicia>0.7f) { 
        std::cout << "Odebra³eœ Mleko" << std::endl; money += 50*mno¿nik2; mleko.restart(); zape³nieniePicia = zape³nieniePicia - 0.025f; } }

    zape³nienieSpanka = zape³nienieSpanka - (spanko.getElapsedTime().asSeconds())/(100*(1/mno¿nik1));
    spanko.restart();
    if (zape³nienieSpanka>= 1) { zape³nienieSpanka = 1; };
    if (zape³nienieSpanka <= 0) { zape³nienieSpanka = 0; };
    spankot³o.setSize(Vector2f(100.f,zape³nienieSpanka*100));
    spankot³o.setPosition(sf::Vector2f(665.f, 20.f + 100.f - zape³nienieSpanka * 100));

    zape³nienieJedzenia = zape³nienieJedzenia - (jedzenie.getElapsedTime().asSeconds()) / (100 * (1 / mno¿nik1));
    jedzenie.restart();
    if (zape³nienieJedzenia >= 1) { zape³nienieJedzenia = 1; };
    if (zape³nienieJedzenia <= 0) { zape³nienieJedzenia = 0; };
    jedzeniet³o.setSize(Vector2f(100.f, zape³nienieJedzenia * 100));
    jedzeniet³o.setPosition(sf::Vector2f(545.f, 20.f + 100.f - zape³nienieJedzenia * 100));

    zape³nieniePicia = zape³nieniePicia - (picie.getElapsedTime().asSeconds()) / (200 * (1 / mno¿nik1));
    picie.restart();
    if (zape³nieniePicia >= 1) { zape³nieniePicia = 1; };
    if (zape³nieniePicia <= 0) { zape³nieniePicia = 0; };
    piciet³o.setSize(Vector2f(100.f, zape³nieniePicia * 100));
    piciet³o.setPosition(sf::Vector2f(785.f, 20.f + 100.f - zape³nieniePicia * 100));
    if (keySpace == 1) { wysokoœæBucketa = wysokoœæBucketa + 20; }
    keySpace = 0;
    wysokoœæBucketa = wysokoœæBucketa - clock.getElapsedTime().asMilliseconds()*15;
    clock.restart();
    if (wysokoœæBucketa < 0) { wysokoœæBucketa = 0; }
    //std::cout << zape³nienieMleka << std::endl;
    //std::cout << Mouse::getPosition(window).x << "   "<< Mouse::getPosition(window).y << std::endl;

    if (keyS == 1){
        graSpanko = 1;
        std::mt19937 generator(std::time(nullptr));
        std::uniform_int_distribution<int> liczbaCou(1, 9);
     //   std::mt19937 generator(std::time(nullptr));
        std::uniform_int_distribution<int> pozycjaX(0, 1200);
     //   std::mt19937 generator(std::time(nullptr));
        std::uniform_int_distribution<int> pozycjaY(300,620);
        spankoLiczbaCou = liczbaCou(generator);
        for (int i{}; i < 9; i++) {
            tabSpankoX[i] = pozycjaX(generator);
            tabSpankoY[i] = pozycjaY(generator);
        }
    }

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
    /////////draw//////////
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
            zape³nienieSpanka = 100.f;
            keyNumber = 0;
        }
        else if (keyNumber != 0) {
            graSpanko = 0;
            //zape³nienieSpanka = zape³nienieSpanka - 0.05;
            keyNumber = 0;
        }
    }


    if (graPicie == 1) {
        window.draw(backgroundPicie);
        waterbucket.setPosition(927.f, 700.f - wysokoœæBucketa);
        window.draw(waterbucket);
        if (wysokoœæBucketa >= 450) {
            graPicie = 0;
            zape³nieniePicia = 100.f;
            keySpace = 0;
            wysokoœæBucketa = 0;
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
            zape³nienieJedzenia = 100.f;
        }
    }
    if (level == 1 && money >= 1000) {
        level = 2;
        money = money - 1000;
        mno¿nik1 = 1.5f;
        mno¿nik2 = 3.f;
        t1.loadFromFile("images/cou2.png");
    }
    else if (level == 2 && money >= 10000) {
        level = 3;
        money = money - 10000;
        mno¿nik1 = 2.1f;
        mno¿nik2 = 9.f;
        t1.loadFromFile("images/cou3.png");
    }
    else if (level == 3 && money >= 100000) {
        level = 4;
        money = money - 100000;
        mno¿nik1 = 3.f;
        mno¿nik2 = 81.f;
        t1.loadFromFile("images/cou4.png");
    }
    else if (level >= 4 && money >= 1000000) {
        level++;
        money = money - 1000000;
        mno¿nik1 = mno¿nik1*1.03f;
        if (mno¿nik1 > 4.3) { mno¿nik1 = 5; }
        mno¿nik2 = mno¿nik2;
    }
    if (money < 0) { money = 0; }

    keySpace = 0;
    dx = 0;
    dy = 0;
    window.draw(tophud);
    window.draw(coin);
    window.draw(text);
    window.draw(poziom);
    window.draw(mlekot³o);
    window.draw(spankot³o);
    window.draw(jedzeniet³o);
    window.draw(piciet³o);
    window.draw(ikonamleko);
    window.draw(ikonajedzenie);
    window.draw(ikonaspanko);
    window.draw(ikonapicie);
    window.display();
    }
    plik.open("save/save.txt", std::ios::out);
    if (plik.good())
    {
        plik << money << std::endl;
        plik << level << std::endl;
        plik << zape³nienieMleka << std::endl;
        plik << zape³nienieSpanka << std::endl;
        plik << zape³nienieJedzenia << std::endl;
        plik << zape³nieniePicia << std::endl;

    }
    else std::cout << "Nie wczytano save'a" << std::endl;
    plik.close();
    return 0;
}
