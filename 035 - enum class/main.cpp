#include "movie.h"
#include <iostream>
#include <string>


int main() {
    MovieDatabase db;

    // TODO: 제목이 "q"이면 입력을 종료하고 요약을 출력하세요.

    while(true){
        // TODO: 영화 제목을 한 줄씩 입력받으세요.
        std::string title;
        std::getline(std::cin, title);

        if(title == "q"){
            break;
        }
        
        // TODO: 각 영화에 대해 장르(Action, Drama, SciFi)와 별점 문자열(예: ★★★★☆)을 읽어
        std::string genre_text, stars;
        std::getline(std::cin, genre_text);
        std::getline(std::cin, stars);

        // TODO: db.addRating(...)으로 누적한 뒤 마지막에 db.printSummary()를 호출하세요.
        db.addRating(title, genre_text, stars);
    }
    std::cout << "Movie Ratings Summary:\n";
    db.printSummary();

    return 0;
}