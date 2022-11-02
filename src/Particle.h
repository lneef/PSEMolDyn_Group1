/*
 * Particle.h
 *
 *  Created on: 23.02.2010
 *      Author: eckhardw
 */

#pragma once

#include <array>
#include <string>

class Particle {

private:
  /**
   * Position of the particle
   */
  std::array<double, 3> x;

  /**
   * Velocity of the particle
   */
  std::array<double, 3> v;

  /**
   * Force effective on this particle
   */
  std::array<double, 3> f;

  /**3
   * Force which was effective on this particle
   */
  std::array<double, 3> old_f;

  /**
   * Mass of this particle
   */
  double m;

  /**
   * Type of the particle. Use it for whatever you want (e.g. to separate
   * molecules belonging to different bodies, matters, and so on)
   */
  int type;

public:
  explicit Particle(int type = 0);

  Particle(const Particle &other);

  Particle(
      // for visualization, we need always 3 coordinates
      // -> in case of 2d, we use only the first and the second
      std::array<double, 3> x_arg, std::array<double, 3> v_arg, double m_arg,
      int type = 0);

  virtual ~Particle();

  const std::array<double, 3> &getX() const;

  const std::array<double, 3> &getV() const;

  const std::array<double, 3> &getF() const;

  const std::array<double, 3> &getOldF() const;

  double getM() const;

  int getType() const;

  bool operator==(Particle &other);

  std::string toString() const;
  
  /**
   * @brief Setter for the effective force acting on the particle. Before f is set to the new value, old_f is set to the old value of f.
   * 
   * @param f Array representing three dimensional vector of forces acting on the particle
  */
  void setF(const std::array<double, 3>& f);

  /**
   * @brief Setter for the position of the particle.
   * 
   * @param x Array represention three dimensional position of the particle
  */

  void setX(const std::array<double, 3>& x);

  /**
   * @brief Setter for the velocity of the particle 
   * 
   * @param v three dimensional vector of the velocities of the particle in all three dimensions 
  */
  void setV(const std::array<double, 3>& v);
};

std::ostream &operator<<(std::ostream &stream, Particle &p);
