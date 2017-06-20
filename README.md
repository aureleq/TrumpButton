# TrumpButton

Make your own Donald Trump button to order your favorite drink thanks to @sigfox!
https://www.youtube.com/watch?v=94eh6RCk3lA

![Button5](pics/button5.jpg)

## Requirements
- Arduino MKRFox1200
- Twilio account to send text message
- @thethings.io sticker to make IOT great again

## Sigfox callback configuration

Create a new custom callback and configure it with your Twilio credentials:

- URL: https://[AccountSID]:[AuthToken]]@api.twilio.com/2010-04-01/Accounts/[AccountSID]/Messages.json
- Content-Type:application/x-www-form-urlencoded
- Body: From=[YourTwilioPhonenumber]]&To=[PhoneNumber]&Body=covfefe!

## Hardware overview

![Button1](pics/button1.jpg)

![Button2](pics/button2.jpg)

![Button3](pics/button3.jpg)

![Button4](pics/button4.jpg)
Switch is opened when pushing the button
