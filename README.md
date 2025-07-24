# Esp 32 data logging
This IoT-based project enables the sending of data from an esp32 microcontrollers via the internet to google sheets where the data can be accessed and monitored almost close to real-time
The data can also be plotted by selecting a column(s) and inserting a chart
## Components
- Esp 32 microcontroller
- dht11 humidity and temperature sensor
- jumper wires
- Moisture sensor
## Software
. Arduino IDE
. A Gmail account
## Directions
- Open your gmail account and navigate to sheets
- Create a new sheet
- Click on extensions >Apps script  and replace the code with the following code;

  function doPost(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  var data = JSON.parse(e.postData.contents);
  sheet.appendRow([new Date(), data.temperature, data.humidity, data.moisture]);
  return ContentService.createTextOutput("Success");

}
- Then deploy > Manage deployments > Create deployment > Select type> Web app> Give a description and select who can access **Anyone** , If you recieve a warning, click advanced and allow access
- Copy the web url which should be in this format **https://script.google.com/macros/s/AKfycbxYnYDTrKrvTEUfSXZgn131CdR1n9jiQw5A9IynI3x1RdcvfoFqyAtw0oSYMajIfv-r/exec**
- Replace the url in the code with this url
- Upload the code and open the sheet to see your data
  - For plots, select a column from the top and select add chart, your plotwill be updated as your values are been uploaded
