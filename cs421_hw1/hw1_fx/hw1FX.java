//HW1FX
//Author: Brett Yeager
//JDK: java version "1.8.0_60"
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.*;
import javafx.geometry.*;
import javafx.collections.*;
import javafx.scene.control.*;
import javafx.event.*;
import java.text.DecimalFormat;
import javafx.scene.control.Alert.*;
/** Hw1FX is the driver for this program
	*@author Brett Yeager
*/
public class hw1FX extends Application {
	//Making all elemnts on the form
	private Label first_name_lbl = new Label("First Name: ");
	private TextField first_name_txt = new TextField();
	private Label last_name_lbl = new Label("Last Name: ");
	private TextField last_name_txt = new TextField();
	private Label size_lbl = new Label("Pizza Size");
	private ChoiceBox pizza_size = new ChoiceBox(FXCollections.observableArrayList("Small", "Medium", "Large"));
	private Label type_lbl = new Label("Pizza Type");
	private ChoiceBox pizza_type = new ChoiceBox(FXCollections.observableArrayList("Pepperoni", "Hawaiian", "Veggie", "Meat", "Special"));
	private CheckBox checkbox1 = new CheckBox("Extra Cheese");
	private CheckBox checkbox2 = new CheckBox("Green Pepper");
	private CheckBox checkbox3 = new CheckBox("Onion");
	private CheckBox checkbox4 = new CheckBox("Mushroom");
	private CheckBox checkbox5 = new CheckBox("Black Olive");
	private CheckBox checkbox6 = new CheckBox("Tomato");
	private CheckBox checkbox7 = new CheckBox("Jalapeno Pepper");
	private Label total_lbl = new Label("Price(Including tax):");
	private Label price_lbl = new Label("$7.42");
	private Button clear_btn = new Button("Clear");
	private Button view_order = new Button("View Order");
	private Button submit = new Button("Submit Order");
	@Override
	/**Start is the entry point of the application
	*@param stage 	The stage passed down by the parent
	*/
	public void start(Stage stage) throws Exception {
		//setting up main grid pane
		stage.setTitle("Brett's Pizza Place");
		final GridPane pane = new GridPane();
		pane.setPadding(new Insets(5, 5, 5, 5)); 
		pane.setAlignment(Pos.CENTER);
		pane.setHgap(5);
		pane.setVgap(5);

		//adding name entry
		pane.add(first_name_lbl, 0,0);
		pane.add(first_name_txt, 1,0);
		pane.add(last_name_lbl, 0,1);
		pane.add(last_name_txt, 1,1);

		//Adding size and type selectors
		pane.add(size_lbl,0,2);
		pane.add(pizza_size,1,2);
		pane.add(type_lbl,0,3);
		pane.add(pizza_type,1,3);

		//making a vbox and adding all the checkboxes to it
		VBox check_group = new VBox(7);
		check_group.getChildren().addAll(checkbox1,checkbox2,checkbox3,checkbox4,checkbox5,checkbox6,checkbox7);
		pane.add(check_group,0,4);

		//Adding total info
		pane.add(total_lbl,0,5);
		pane.add(price_lbl,1,5);

		//Adding hbox for buttons
		HBox btn_group = new HBox(7);
		btn_group.getChildren().addAll(clear_btn,view_order,submit);
		pane.add(btn_group,0,6);

		//Setting values
		pizza_type.setValue("Pepperoni");
		pizza_size.setValue("Medium");

		//Binding event to watch for a change in price
		pizza_size.setOnAction(changePrice);
		pizza_type.setOnAction(changePrice);
		checkbox1.setOnAction(changePrice);
		checkbox2.setOnAction(changePrice);
		checkbox3.setOnAction(changePrice);
		checkbox4.setOnAction(changePrice);
		checkbox5.setOnAction(changePrice);
		checkbox6.setOnAction(changePrice);
		checkbox7.setOnAction(changePrice);

		//Binding the clear button
		clear_btn.setOnAction(clearForm);

		//binding the submit button
		submit.setOnAction(submitForm);

		//binding the view order button
		view_order.setOnAction(viewForm);

		//adding the pane to a scene and passing it to the parent stage
		Scene scene = new Scene(pane);
		stage.setScene(scene);
		stage.show();
	}
	//This lamda function watches for a price change
	//adapted from hw1FXML
	EventHandler changePrice = e-> {
		Integer base_price = 0;
		Integer size_add = 0;
		Double size_top_add = 0.0;
		Double add_top = 0.0;
		Double total = 0.00;
		DecimalFormat df = new DecimalFormat("#.00");
		String P_type = pizza_type.getValue().toString();
		String P_size = pizza_size.getValue().toString();
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
		if(checkbox1.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(checkbox2.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(checkbox3.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(checkbox4.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(checkbox5.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(checkbox6.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		if(checkbox7.isSelected())
		{
			add_top += .5 + size_top_add;
		}
		//Updating the total
		total = ((double)base_price + (double)size_add + add_top) * 1.06;
		price_lbl.setText("$" + df.format(total));
	};

	//This lamda function resets the form
	//adapted for hw1FXML
	EventHandler clearForm = e -> {
		//Resting values
		pizza_type.setValue("Pepperoni");
		pizza_size.setValue("Medium");
		checkbox1.setSelected(false);
		checkbox2.setSelected(false);
		checkbox3.setSelected(false);
		checkbox4.setSelected(false);
		checkbox5.setSelected(false);
		checkbox6.setSelected(false);
		checkbox7.setSelected(false);
		price_lbl.setText("$7.42");
	};

	//This lamda function shows the submit order by an alert
	//adapted for hw1FXML
	EventHandler submitForm = e -> {
		//Creating an alert message box
		Alert alert = new Alert(AlertType.INFORMATION);
		alert.setTitle("Total");
		alert.setHeaderText("This is your order total");
		alert.setResizable(true);
		alert.getDialogPane().setPrefSize(280, 220);
		String P_type = pizza_type.getValue().toString();
		String P_size = pizza_size.getValue().toString();
		String s = "You are about to place an order for a " + P_size + " " + P_type + " pizza. The total is: " + price_lbl.getText();  
		alert.setContentText(s);
		alert.show();
	};

	//This lamda function shows the order list
	//adapted for hw1FXML
	EventHandler viewForm = e -> {
		Stage orders = new Stage();
		final GridPane pane = new GridPane();
		pane.add(new Label("Name: "),0,0);
		pane.add(new Label(first_name_txt.getText() + " " + last_name_txt.getText()),1,0);
		pane.add(new Label("Size: "),0,1);
		pane.add(new Label(pizza_size.getValue().toString()),1,1);
		pane.add(new Label("Type: "),0,2);
		pane.add(new Label(pizza_type.getValue().toString()),1,2);
		pane.add(new Label("Price: "),0,3);
		pane.add(new Label(price_lbl.getText()),1,3);
		Scene o_scene = new Scene(pane);
		orders.setScene(o_scene);
		orders.show();
	};
}