import java.net.URL;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.collections.*;
import javafx.scene.control.*;
import java.text.DecimalFormat;
import javafx.scene.layout.GridPane;
/** FormController handles the events for Form.fxml
	*@author Brett Yeager
*/
public class FormController implements Initializable {
	//List of elements needed from the fxml
	@FXML
	private ChoiceBox PizzaType;
	@FXML
	private ChoiceBox PizzaSize;
	@FXML
	private TextField FirstName;
	@FXML
	private TextField LastName;
	@FXML
	private Label TotalPrice;
	@FXML
	private CheckBox CheckBox1;
	@FXML
	private CheckBox CheckBox2;
	@FXML
	private CheckBox CheckBox3;
	@FXML
	private CheckBox CheckBox4;
	@FXML
	private CheckBox CheckBox5;
	@FXML
	private CheckBox CheckBox6;
	@FXML
	private CheckBox CheckBox7;
	@FXML
	/** ChangePrice is triggered when an emement on the form changes. It updates the total price.
	*@param event 	The event raised on the form
	*/
	private void ChangePrice(ActionEvent event) {
		Integer base_price = 0;
		Integer size_add = 0;
		Double size_top_add = 0.0;
		Double add_top = 0.0;
		Double total = 0.00;
		DecimalFormat df = new DecimalFormat("#.00");
		String P_type = PizzaType.getValue().toString();
		String P_size = PizzaSize.getValue().toString();
		//Checking size of pizza
		switch(P_size)
		{
			case "Small":
				size_add = 0;
				size_top_add = 0.00;
				break;
			case "Medium":
				size_add = 2;
				size_top_add = .5;
				break;
			case "Large":
				size_add = 4;
				size_top_add = 1.00;
				break;
		}
		//Checking type of pizza
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
		//Checking for additional toppings
		if(CheckBox1.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(CheckBox2.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(CheckBox3.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(CheckBox4.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(CheckBox5.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(CheckBox6.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(CheckBox7.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		//Updating the total
		total = ((double)base_price + (double)size_add + add_top) * 1.06;
		TotalPrice.setText("$" + df.format(total));
	}
	@FXML
	/** ClearForm is triggered when the clear button is clicked. It resets the form.
	*@param event 	The event raised on the form
	*/
	private void ClearForm(ActionEvent event)
	{
		//Resting values
		PizzaType.setValue("Pepperoni");
		PizzaSize.setValue("Medium");
		CheckBox1.setSelected(false);
		CheckBox2.setSelected(false);
		CheckBox3.setSelected(false);
		CheckBox4.setSelected(false);
		CheckBox5.setSelected(false);
		CheckBox6.setSelected(false);
		CheckBox7.setSelected(false);
		TotalPrice.setText("$7.42");
	}
	@FXML
	/** SubmitForm is triggered when the order button is clicked. It shows a total message to the user
	*@param event 	The event raised on the form
	*/
	private void SubmitForm(ActionEvent event)
	{
		//Creating an alert message box
		Alert alert = new Alert(AlertType.INFORMATION);
		alert.setTitle("Total");
		alert.setHeaderText("This is your order total");
		alert.setResizable(true);
		alert.getDialogPane().setPrefSize(280, 220);
		String P_type = PizzaType.getValue().toString();
		String P_size = PizzaSize.getValue().toString();
		String s = "You are about to place an order for a " + P_size + " " + P_type + " pizza. The total is: " + TotalPrice.getText();  
		alert.setContentText(s);
		alert.show();
	}
	@FXML
	/** ViewOrder is triggered when the view order button is clicked. It shows breakdown of the pizza ordered.
	*@param event 	The event raised on the form
	*/
	private void ViewOrder(ActionEvent event)
	{
		Stage orders = new Stage();
		final GridPane pane = new GridPane();
		pane.add(new Label("Name: "),0,0);
		pane.add(new Label(FirstName.getText() + " " + LastName.getText()),1,0);
		pane.add(new Label("Size: "),0,1);
		pane.add(new Label(PizzaSize.getValue().toString()),1,1);
		pane.add(new Label("Type: "),0,2);
		pane.add(new Label(PizzaType.getValue().toString()),1,2);
		pane.add(new Label("Price: "),0,3);
		pane.add(new Label(TotalPrice.getText()),1,3);
		Scene o_scene = new Scene(pane);
		orders.setScene(o_scene);
		orders.show();
	}
	@Override
	public void initialize(URL url, ResourceBundle rb) {
		TotalPrice.setText("$7.42");
	}
}