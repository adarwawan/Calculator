compilecontroller : mClassController.cpp ClassController.cpp Reader.cpp ../Equation/Equation.cpp ../Equation/Expression.cpp ../Token/Token.cpp ../Token/Number.cpp ../Token/NumberArab.cpp ../Token/NumberRomawi.cpp ../Extension/Extension.cpp Saver.cpp Logger.cpp Log.cpp ../Token/Logic.cpp ../Equation/EquationException.cpp
  g++ mClassController.cpp ClassController.cpp Reader.cpp ../Equation/Equation.cpp ../Equation/Expression.cpp ../Token/Token.cpp ../Token/Number.cpp ../Token/NumberArab.cpp ../Token/NumberRomawi.cpp ../Extension/Extension.cpp Saver.cpp Logger.cpp Log.cpp ../Token/Logic.cpp ../Equation/EquationException.cpp -o ClassController
compilelogger : Log.cpp Logger.cpp mLogger.cpp
  g++ Log.cpp Logger.cpp mLogger.cpp -o Logger
compilereader : Reader.cpp mReader.cpp
  g++ Reader.cpp mReader.cpp -o Reader
compilesaver : mSaver.cpp Saver.cpp Logger.cpp Log.cpp
  g++ mSaver.cpp Saver.cpp Logger.cpp Log.cpp -o Saver
  
runsaver : Saver.exe
  Saver.exe
runreader : Reader.exe
  Reader.exe
runlogger : Logger.exe
  Logger.exe
runcontroller : ClassController.exe
  ClassController.exe