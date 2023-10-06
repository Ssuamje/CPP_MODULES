//TODO!!!
//TODO!!!
//TODO!!!
//TODO!!!
/*           CSV파일 지우기              */
//TODO!!!
//TODO!!!
//TODO!!!
//TODO!!!

#include "BitcoinExchange.hpp"

int main() {
    // 비트코인은 2009-01-02(외국날짜)에 도입되었다.
    // 파일 읽기 - data.csv - 있는지 없는지 확인
    // 알맞게 파싱되어있는지, 잘못된 값은 없는지 확인
    // 자료구조에 저장하기
    
    // 파일 읽기 - av[1]
    // 알맞게 파싱되어있는지, 잘못된 값은 없는지 확인(양수인 int 범위의 float)
    // line by line으로 수행한다. - 에러시 문구를 출력하고 종료하지 않는다.

    BitcoinExchange be = BitcoinExchange();
    be.readCsv(BitcoinExchange::DEFAULT_FILE_DIRECTORY);

    return 0;
}