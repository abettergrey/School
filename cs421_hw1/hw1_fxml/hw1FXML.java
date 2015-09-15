//HW1FXML
//Author: Brett Yeager
//JDK: java version "1.8.0_60"
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
/** Hw1FXML is the driver for this program
	*@author Brett Yeager
*/
public class hw1FXML extends Application {
	@Override
	public void start(Stage stage) throws Exception {
		stage.setTitle("Brett's Pizza Place");
		//linking xml to the stage
		Parent root = FXMLLoader.load(getClass().getResource("Form.fxml"));
		Scene scene = new Scene(root);
		stage.setScene(scene);
		stage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}