import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.collections.*;
import javafx.scene.control.*;
import java.text.DecimalFormat;
public class FormController implements Initializable {
@FXML
private ChoiceBox PizzaType;
@FXML
private ChoiceBox PizzaSize;
@FXML
private TextField FirstName;
@FXML
private Label TotalPrice;
@FXML
private void ChangePrice(ActionEvent event) {
	Integer base_price = 0;
	Integer size_add = 0;
	Double total = 0.00;
	DecimalFormat df = new DecimalFormat("#.00");
	String P_type = PizzaType.getValue().toString();
	String P_size = PizzaSize.getValue().toString();
	switch(P_size)
	{
		case "Small":
			size_add = 0;
			break;
		case "Medium":
			size_add = 2;
			break;
		case "Large":
			size_add = 4;
			break;
	}
	switch(P_type)
	{
		case "Pepperoni":
			base_price = 5;
			break;
		case "Veggie":
			base_price = 6;
			break;
		case "Hawaiian": 
			base_price = 7;
			break;
		case "Meat":
			base_price = 7;
			break;
		case "Special":
			base_price = 8;
			break;
	}
	total = (double)base_price + (double)size_add;
	TotalPrice.setText("$" + df.format(total));
}
@Override
public void initialize(URL url, ResourceBundle rb) {
	TotalPrice.setText("$7.00");
}
}