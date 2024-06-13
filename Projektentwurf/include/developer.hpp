#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <string>
#include <iostream>

// Base class Developer
/**
 * @brief Base class for all types of Developers.
 */
class Developer {
public:
    /**
     * @brief Constructor for Developer class.
     * @param name The name of the developer.
     * @param alias The alias of the developer.
     */
    Developer(const std::string& name, const std::string& alias);

    /**
     * @brief Virtual destructor for Developer class.
     */
    virtual ~Developer() = default;

    /**
     * @brief Get the name of the developer.
     * @return The name of the developer.
     */
    std::string getName() const;

    /**
     * @brief Get the alias of the developer.
     * @return The alias of the developer.
     */
    std::string getAlias() const;

    /**
     * @brief Get the logo of the developer.
     * @return The logo of the developer.
     */
    std::string getLogo() const;

    /**
     * @brief Static method to simulate drinking coffee.
     */
    static void drink_coffee();

    /**
     * @brief Load a logo from a file.
     * @param filename The name of the file containing the logo.
     */
    void load_logo_from_file(const std::string& filename);

    /**
     * @brief Pure virtual method to solve a problem.
     */
    virtual void solve_problem() const = 0;

    /**
     * @brief Overloaded output stream operator for Developer.
     * @param os The output stream.
     * @param dev The Developer object.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Developer& dev);

private:
    std::string name; ///< Name of the developer
    std::string alias; ///< Alias of the developer
    std::string logo; ///< Logo of the developer
};

// Class representing a Junior Developer
/**
 * @brief Class representing a Junior Developer.
 */
class JuniorDeveloper : public Developer {
public:
    /**
     * @brief Constructor for JuniorDeveloper class.
     * @param name The name of the junior developer.
     * @param alias The alias of the junior developer.
     */
    JuniorDeveloper(const std::string& name, const std::string& alias);

    /**
     * @brief Implementation of solve_problem method for JuniorDeveloper.
     */
    void solve_problem() const override;
};

// Class representing a Senior Developer
/**
 * @brief Class representing a Senior Developer.
 */
class SeniorDeveloper : public Developer {
public:
    /**
     * @brief Constructor for SeniorDeveloper class.
     * @param name The name of the senior developer.
     * @param alias The alias of the senior developer.
     */
    SeniorDeveloper(const std::string& name, const std::string& alias);

    /**
     * @brief Implementation of solve_problem method for SeniorDeveloper.
     */
    void solve_problem() const override;
};

#endif // DEVELOPER_HPP