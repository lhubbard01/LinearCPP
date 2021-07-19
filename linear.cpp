#include <cmath>

#include <iostream>
#include <vector>
#include <random>

using std::vector;
using std::cout;
using std::endl;


class Vec : public vector<double>
{
private:
  vector<double> vec;
  int dim;
public:
  Vec(const int dim);
  double operator * (const Vec & other);
  //Vec operator + (const Vec & other);
  //Vec operator += (const Vec & other);
  

  //Vec operator -= (const Vec & other);
  //Vec operator - (const Vec *, const Vec & other);
};


std::default_random_engine gen;
std::normal_distribution<double> standard_normal(0.0, 1.0);






Vec::Vec(const int dim) : vector<double>(dim), dim (dim)
{
}


double
Vec::operator * (const Vec & other)
{
  double dot = 0.0;

  if (this->dim != other.dim)
      return -1;

  for (auto iterthis = this->cbegin(), iterother = other.cbegin(); 
       iterthis != this->end();
       ++iterthis, ++iterother) 
  {
    dot += (*iterthis) * (*iterother);
  }

  return dot;
}


/*
class LinearBase
{

private:
    Vec params;
    int DoF; // Degrees of Freedom, i.e. |regressors|
    double bias;

public:
  LinearBase(const int DoF);
  double operator() (const Vec & X) const; // 
  double L1Norm() const;
  double eval(const Vec &) const;
  double der();
};


double
randomN(void)
{
  return standard_normal(gen);
}


LinearBase::LinearBase(const int dof) : params(dof), dof(dof)
{
  bias = randomN();
  for (int i = 0; i < dof; ++i)
    params.push_back(randomN());
}




double 
LinearBase::L1Norm(void) const
{
  double accum = 0.0;
  for (auto iter = this->cbegin(); iter != this->end; ++iter)
    accum += (*iter);
  return accum;
}




double 
LinearBase::eval(const Vec & X) const
{
  return this->params * X + this->bias; // inner product with weights
}


double
LinearBase::operator() (const Vec & X) const
{
  return eval(X);
}

class LinearLasso: public LinearBase
{
private:
  double alpha;
public:
  LinearLasso(const int dof, const double alpha) : LinearBase(dof), alpha(alpha)
  {
    }
  double regularize() const;
  double der() const;
  double eval(const Vec &) const;
};


double
LinearLasso::eval(const Vec & X) const
{

  double err = LinearBase::eval(X);
  double total_err = reg(err);
  return total_err;
}


double
LinearLasso::regularize(const double err) const
{
  double accum = 0.0;
  for (auto iter = this->params.cbegin(); iter != this->params.end(); ++iter)
    accum += abs((*iter));
  return err + alpha * accum;
}



void
sign(const Vec & params, Vec & writeTo)
{

  for (auto iter = params.cbegin(); iter != params.end(); ++iter)
    writeTo.push_back(signbit(*iter));
} 




double
LinearLasso::der(void) const
{
  Vec derivative(dof);
  return alpha * sign(params, derivative);
}


class LinearRidge: public LinearBase
{
private:
  double alpha;
public:
  LinearRidge(const int dof, const double alpha) : LinearBase(dof), alpha(alpha){}
  double regularize() const;
  double der() const;
};


class LinearElasticNet: public LinearRidge, public LinearLasso
{
private: 
  double alpha;
  double beta;
public:
  LinearElasticNet(const int dof, const double alpha, const double beta) : 
    LinearLasso(dof, alpha), LinearRidge(dof, alpha) , beta(beta) 
  { }



  operator () (const vector<double> X) const; // calls eval
  double eval(const vector<double> X)  const; //  
  double regularize() const;
};









double
LinearRidge::regularize(const double err) const
{
  double reg_loss = err + alpha * (this->params * this.params) / 2;
  return reg_loss;
}

double 
LinearRidge::der(void) const
{
  return alpha * LinearBase::L1Norm();
}

*/
void
init(Vec & v, const int n_items)
{
  for (int i = 0; i < n_items; ++i)
  {
    double x = standard_normal(gen);
    cout << x << " ";
    v.push_back(x);
  }

  cout << endl;
}

int main()
{
  Vec v1(9), v2(9);
  init(v1, 9);
  init(v2, 9);
  double out = v1 * v2;
  cout << out << endl;
  return 0;      
}
