import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
public class hw1FXML extends Application {
	@Override
	public void start(Stage stage) throws Exception {
		stage.setTitle("In production");
		Parent root = FXMLLoader.load(getClass().getResource("Form.fxml"));
		Scene scene = new Scene(root);
		stage.setScene(scene);
		stage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}