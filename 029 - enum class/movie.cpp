#include "movie.h"
#include <iostream>

// TODO: genreToString을 구현하세요.
std::string genreToString(Genre genre){
    switch (genre) {
        case Genre::Action:
            return "Action";
        case Genre::Drama:
            return "Drama";
        case Genre::SciFi:
            return "SciFi";
        default:
            return "Unknown";
        }
}

// TODO: stringToGenre를 구현하세요.
// Genre stringToGenre(std::string_view text);
Genre stringToGenre(std::string_view text){
    if (text == "Action") return Genre::Action;
    if (text == "Drama") return Genre::Drama;
    if (text == "SciFi") return Genre::SciFi;

    return Genre::Drama; // or 기본값
}

// TODO: 별점 문자열에서 검은 별(★) 개수를 세어 정수로 반환하세요.
// int starsToInt(std::string_view stars);
int starsToInt(std::string_view stars){
    int count = 0;

    for (size_t i = 0; i + 2 < stars.size(); i++) {
        // ★ = E2 98 85
        if ((unsigned char)stars[i] == 0xE2 &&
            (unsigned char)stars[i+1] == 0x98 &&
            (unsigned char)stars[i+2] == 0x85) {
            count++;
            i += 2; // 3바이트 skip
        }
    }

    return count;
}

// TODO: addRating에서 제목별 장르와 평점을 저장하세요.
void MovieDatabase::addRating(const std::string& title, std::string_view genre_text, std::string_view stars) {
    Genre genre = stringToGenre(genre_text);
    int rating = starsToInt(stars);

    genres_[title] = genre;
    ratings_[title].push_back(rating);
}

// TODO: printSummary에서 제목 알파벳 순으로
// "제목: N ratings, average rating M stars, genre: 장르"
// 형식의 요약을 출력하세요.
void MovieDatabase::printSummary() const {
    for (const auto& [title, genre] : genres_) {
        const auto& ratings = ratings_.at(title);

        int sum = 0;
        for (int r : ratings) sum += r;

        int average = sum / ratings.size();

        std::cout << title << ": " << ratings.size()
                  << " ratings, average rating "
                  << average << " stars, genre: "
                  << genreToString(genre) << std::endl;
    }
}