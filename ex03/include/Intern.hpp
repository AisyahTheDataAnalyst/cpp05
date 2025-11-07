/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:07:12 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/07 14:43:59 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		//OCF
		Intern();
		Intern &operator=(const Intern &other);
		Intern(const Intern &other);
		~Intern();
		
		//method
		AForm *makeForm(std::string form, std::string target) const;
		// AForm *makeSCForm(std::string target);
		// AForm *makeRRForm(std::string target);
		// AForm *makePPForm(std::string target);
};
#endif