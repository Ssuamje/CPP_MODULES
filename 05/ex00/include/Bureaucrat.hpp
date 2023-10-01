#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& ref);
        Bureaucrat(const std::string& name, int grade);
        virtual ~Bureaucrat();

        Bureaucrat&	operator=(const Bureaucrat& ref);

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw(); // throw()는 예약어로서, NoExcept로 이 함수는 절대로 예외를 뱉지 않음을 얘기한다.
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};



#endif
