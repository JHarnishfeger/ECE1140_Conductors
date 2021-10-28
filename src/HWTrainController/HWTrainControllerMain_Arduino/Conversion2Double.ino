void convert2Numbers()
{
  Kp = KpString.toDouble();
  Ki = KiString.toDouble();
  commandedSpeed = commandedSpeedString.toDouble();
  currentSpeed = currentSpeedString.toDouble();
  suggestedSpeed = suggestedSpeedString.toDouble();
  speedLimit = speedLimitString.toDouble();
  authority = authorityString.toInt();
}
