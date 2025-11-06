/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:16:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/06 13:28:13 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_formName;
		bool				_isItSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// OCF
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		//methods
		const std::string &getFormName() const;
		const bool &getIsItSigned() const;
		const int &getGradeToSign() const;
		const int &getGradeToExecute() const;
		void beSigned(const Bureaucrat &pic);

		//exception classes
		class GradeTooHighException: public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &value);

#endif