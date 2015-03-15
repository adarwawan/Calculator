compile : Reader/Reader.cpp Equation/Equation.cpp Equation/Expression.cpp Token/Token.cpp Number/NumberArab.cpp Number/NumberRomawi.cpp Extension/Extension.cpp Saver/Saver.cpp Logger/Logger.cpp Logger/Log.cpp Logic/Logic.cpp Manager/Manager.cpp Calculator.cpp
  g++ Reader/Reader.cpp Equation/Equation.cpp Equation/Expression.cpp Token/Token.cpp Number/NumberArab.cpp Number/NumberRomawi.cpp Extension/Extension.cpp Saver/Saver.cpp Logger/Logger.cpp Logger/Log.cpp Logic/Logic.cpp Manager/Manager.cpp Calculator.cpp -o e
run : e.exe
  e.exe