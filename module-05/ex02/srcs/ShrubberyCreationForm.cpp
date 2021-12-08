#include <ShrubberyCreationForm.hpp>

const std::string ShrubberyCreationForm::shrubbery_name_ = "ShrubberyCreation";

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	Form(shrubbery_name_, target, require_sign_to_grade_, require_exe_to_grade_)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void) other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::action() const
{
	const std::string tree = "\n"
	"      /\\\n"
	"     /\\*\\\n"
	"    /\\O\\*\\\n"
	"   /*/\\/\\/\\\n"
	"  /\\O\\/\\*\\/\\\n"
	" /\\*\\/\\*\\/\\/\\\n"
	"/\\O\\/\\/*/\\/O/\\\n"
	"      ||\n"
	"      ||\n"
	"      ||\n";

	const std::string file_path = "./" + GetTarget() + "_shrubbery";
	std::ofstream ofs(file_path);

	if (!ofs)
	{
		throw(std::ofstream::failure("Failed to open file"));
	}
	ofs << tree << std::flush;
	if (!ofs)
	{
		throw(std::ofstream::failure("Failed to write tree"));
	}
}
